/*
 * Score.c
 * Mark Hampton
 *
 */


#define INCL_WIN
#define INCL_GPI
#define INCL_DOS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <os2.h>
#include "score.h"

HAB   hab = NULL;
USHORT xChar = 0, yChar = 0;

char szPlayers [2][256] =
   {
   "Mark",
   "Gnu"
   };

char szAppName [] = "Darts";


#define NUM_POINTS      7
#define NUM_HITS        3
#define FILLET          20

USHORT usScore [2];

typedef struct
   {
   USHORT usNumHits;
   USHORT usScore;
   } SCORE;

SCORE scScore [2][NUM_POINTS];


static PSZ apszLabels [NUM_POINTS] = 
   {
   "20",
   "19",
   "18",
   "17",
   "16",
   "15",
   "O",
   };

static PSZ apszHits [NUM_HITS+1] = 
   {
   "",
   "/",
   "X",
   "O",
   };

static void InitScore (void)
   {
   USHORT      i;

   usScore [0] = 0;
   usScore [1] = 0;
   for (i=0; i < NUM_POINTS; i++)
      {
      scScore [0][i].usNumHits = 0;
      scScore [0][i].usScore = 0;
      scScore [1][i].usNumHits = 0;
      scScore [1][i].usScore = 0;
      }
   }


static void CalcRects (HWND hwnd, 
                       RECTL arclScore [3],
                       RECTL aarclRects [3] [NUM_POINTS])
   {
   RECTL    rcl;
   USHORT   y, i, j;

   WinQueryWindowRect (hwnd, &rcl);

   /* prepare the 20's left and right rects */
   aarclRects [0] [0].yTop    = rcl.yTop - 3 * yChar;
   y = (USHORT)(aarclRects [0] [0].yTop - (rcl.yBottom + yChar)) / NUM_POINTS;
   aarclRects [0] [0].yBottom = aarclRects [0] [0].yTop - y;
   aarclRects [0] [0].xLeft   = rcl.xLeft;
   aarclRects [0] [0].xRight  = rcl.xRight / 2 - 3 * xChar;

   arclScore [0].yTop    = rcl.yTop;
   arclScore [0].yBottom = rcl.yTop - 3 * yChar;
   arclScore [0].xLeft   = rcl.xLeft;
   arclScore [0].xRight  = rcl.xRight / 2 - 3 * xChar;

   arclScore [1].yTop    = arclScore [0].yTop;
   arclScore [1].yBottom = arclScore [0].yBottom;
   arclScore [1].xLeft   = arclScore [0].xRight + 6 * xChar;
   arclScore [1].xRight  = rcl.xRight;

   arclScore [2].yTop    = arclScore [0].yTop;
   arclScore [2].yBottom = arclScore [0].yBottom;
   arclScore [2].xLeft   = arclScore [1].xLeft + 1;
   arclScore [2].xRight  = arclScore [1].xRight - 1;

   aarclRects [1] [0].yTop      = aarclRects [0] [0].yTop;
   aarclRects [1] [0].yBottom   = aarclRects [0] [0].yBottom;
   aarclRects [1] [0].xLeft     = aarclRects [0] [0].xRight + 6 * xChar;
   aarclRects [1] [0].xRight    = rcl.xRight;

   aarclRects [2] [0].yTop     = aarclRects [0] [0].yTop;
   aarclRects [2] [0].yBottom  = aarclRects [0] [0].yBottom;
   aarclRects [2] [0].xLeft    = aarclRects [0] [0].xRight + 2;
   aarclRects [2] [0].xRight   = aarclRects [1] [0].xLeft - 2;

   for (i = 1; i < NUM_POINTS; i++)
      {
      for (j = 0; j < 3; j++)
         {
         aarclRects [j] [i].xLeft   = aarclRects [j] [i-1].xLeft;
         aarclRects [j] [i].xRight  = aarclRects [j] [i-1].xRight;
         aarclRects [j] [i].yTop    = aarclRects [j] [i-1].yTop - y;
         aarclRects [j] [i].yBottom = aarclRects [j] [i-1].yBottom - y;
         }
      }
   }


static void IconRect (HWND hwnd, PRECTL prcl)
   {
   RECTL rcl;

   WinQueryWindowRect (hwnd, &rcl);

   prcl->xLeft  = rcl.xRight / 2 - 16;
   prcl->xRight = prcl->xLeft + 32;
   prcl->yBottom= rcl.yTop - yChar * 2 + 2;
   prcl->yTop   = prcl->yBottom + 32;
   }

static void DoCreate (HWND hwnd)
   {
   FONTMETRICS fm;
   HPS         hps;
   POINTL      aptl [TXTBOX_COUNT];

   hps = WinGetPS (hwnd);

   if (hps == NULL)
      return;

   if (GPI_ERROR == GpiQueryFontMetrics (hps, sizeof fm, &fm))
      {
      WinReleasePS (hps);
      return;
      }

   /* base xChar and yChar on the letter 'X' */
   GpiQueryTextBox (hps, 1, "X", TXTBOX_COUNT, aptl);
   xChar = (USHORT) (aptl [TXTBOX_TOPRIGHT].x -
                     aptl [TXTBOX_TOPLEFT].x);
   yChar = (USHORT) (fm.lMaxBaselineExt);

   WinReleasePS (hps);
   }




#define MAXWEIGHT 25

static void Mark (HPS hps, USHORT uHits, PRECTL prcl)
   {
   RECTL   rclTemp;
   POINTL  ptlTL, ptlBR, ptlTR, ptlBL;
   LONG    lxQtr, lyQtr;
   USHORT   i, j, uWeight;

   rclTemp = *prcl;
   lxQtr = (prcl->xRight - prcl->xLeft)   / 4;
   lyQtr = (prcl->yTop   - prcl->yBottom) / 8;
   uWeight = min (MAXWEIGHT, (lxQtr / xChar) * 2);


   WinInflateRect (hab, &rclTemp, -lxQtr, -lyQtr);

//   rclTemp.xLeft   += lxQtr;
//   rclTemp.xRight  -= lxQtr;
//   rclTemp.yTop    -= lyQtr;
//   rclTemp.yBottom += lyQtr;

   ptlTL.x = rclTemp.xLeft ; ptlTL.y = rclTemp.yTop;
   ptlTR.x = rclTemp.xRight; ptlTR.y = rclTemp.yTop;
   ptlBL.x = rclTemp.xLeft ; ptlBL.y = rclTemp.yBottom;
   ptlBR.x = rclTemp.xRight; ptlBR.y = rclTemp.yBottom;

   WinFillRect (hps, prcl, SYSCLR_APPWORKSPACE);

   for (j=0; j < uWeight; j++)
      {
      if (uHits)
         GpiMove (hps, &ptlTR), GpiLine (hps, &ptlBL);
   
      if (uHits > 1)
         GpiMove (hps, &ptlTL),    GpiLine (hps, &ptlBR);
   
      if (uHits > 2)
         GpiMove (hps, &ptlTL),    GpiBox (hps, DRO_OUTLINE, &ptlBR,
                                           lxQtr * 4, lyQtr * 8);
      ptlTL.x++; ptlTR.x++; 
      ptlBL.x++; ptlBR.x++; 
      }     
   }



static void DoPaint (HWND hwnd)
   {
   HPS      hps;
   RECTL    rcp, rcl, rclTemp;
   POINTL   ptlTL1, ptlBR1, ptlTL2, ptlBR2;
   RECTL    aarclRects [3] [NUM_POINTS], arclScore [3];
   USHORT   i, j;
   char     szTemp [256];
   HPOINTER hptr;

   CalcRects (hwnd, arclScore, aarclRects);

   hps = WinBeginPaint (hwnd, NULL, &rcp);
   WinQueryWindowRect (hwnd, &rcl);

   WinFillRect (hps, &rcp, SYSCLR_APPWORKSPACE);

//   GpiSetLineWidth (hps, MAKEFIXED (100,0));

   /* vertical rectangle */
   ptlTL1.x = rcl.xRight / 2 - 2 * xChar;
   ptlTL1.y = rcl.yTop - 1;
   ptlBR1.x = ptlTL1.x + 4 * xChar;
   ptlBR1.y = rcl.yBottom;
   ptlTL2.x = 1;
   ptlTL2.y = rcl.yTop - 1;
   ptlBR2.x = rcl.xRight - 1;
   ptlBR2.y = rcl.yTop - 1 - yChar * 2;

   GpiSetColor (hps, CLR_BLACK);
   GpiMove (hps, &ptlTL1);
   GpiBox (hps, DRO_OUTLINE, &ptlBR1, FILLET, FILLET);
   GpiMove (hps, &ptlTL2);
   GpiBox (hps, DRO_OUTLINE, &ptlBR2, FILLET, FILLET);

   ptlTL1.x++; ptlTL1.y--;
   ptlBR1.x--; ptlBR1.y++;
   ptlTL2.x++; ptlTL2.y--;
   ptlBR2.x--; ptlBR2.y++;

   GpiSetColor (hps, CLR_PALEGRAY);
   GpiMove (hps, &ptlTL1);
   GpiBox (hps, DRO_FILL, &ptlBR1, FILLET, FILLET);
   GpiMove (hps, &ptlTL2);
   GpiBox (hps, DRO_FILL, &ptlBR2, FILLET, FILLET);

   GpiSetColor (hps, CLR_BLACK);

   /* left name */
   rclTemp.xLeft   = 1;
   rclTemp.xRight  = rcl.xRight / 2 - 2 * xChar;
   rclTemp.yTop    = rcl.yTop - 1;
   rclTemp.yBottom = rcl.yTop - 1 - yChar * 2;

   if (usScore[0])
      sprintf (szTemp, "%s (+%d)", szPlayers [0], usScore [0]);
   else
      strcpy (szTemp, szPlayers [0]);
   WinDrawText (hps, -1, szTemp, &rclTemp, 0, 0,
                DT_VCENTER | DT_CENTER | DT_TEXTATTRS);

   /* right name */
   rclTemp.xLeft   = rclTemp.xRight + 4 * xChar;
   rclTemp.xRight  = rcl.xRight - 1;

   if (usScore[1])
      sprintf (szTemp, "%s (+%d)", szPlayers [1], usScore [1]);
   else
      strcpy (szTemp, szPlayers [1]);
   WinDrawText (hps, -1, szTemp, &rclTemp, 0, 0, 
                DT_VCENTER | DT_CENTER | DT_TEXTATTRS);

   /* draw icon */
   hptr = WinLoadPointer (HWND_DESKTOP, 0, 1);
   IconRect (hwnd, &rclTemp);
   WinDrawPointer (hps, rclTemp.xLeft, rclTemp.yBottom, hptr, DP_NORMAL);
   WinDestroyPointer (hptr);

   /* paint each line */
   for (i=0; i < NUM_POINTS; i++)
      {
      WinDrawText (hps, -1, apszLabels [i], &(aarclRects [2] [i]), 0, 0,
                   DT_VCENTER | DT_CENTER | DT_TEXTATTRS);
      j = scScore [0][i].usNumHits > NUM_HITS ? NUM_HITS : 
          scScore [0][i].usNumHits;
      Mark (hps, j, &(aarclRects [0] [i]));

//      WinDrawText (hps, -1, apszHits [j], &(aarclRects [0] [i]), 0, 0,
//                   DT_VCENTER | DT_CENTER | DT_TEXTATTRS);
      j = scScore [1][i].usNumHits > NUM_HITS ? NUM_HITS : 
          scScore [1][i].usNumHits;
      Mark (hps, j, &(aarclRects [1] [i]));
//      WinDrawText (hps, -1, apszHits [j], &(aarclRects [1] [i]), 0, 0,
//                   DT_VCENTER | DT_CENTER | DT_TEXTATTRS);
      }
      
   WinEndPaint (hps);
   }




static USHORT Points (USHORT i)
   {
   switch (i)
      {
      case 0:
         return 20;

      case 1:
         return 19;

      case 2:
         return 18;

      case 3:
         return 17;

      case 4:
         return 16;

      case 5:
         return 15;

      case 6:
         return 25;

      default:
         return 0;
      }
   }

static void DoMouse (HWND hwnd, USHORT x, USHORT y, BOOL bHit, BOOL bDouble)
   {
   RECTL    aarclRects [3] [NUM_POINTS], arclScore [3], rclIcon;
   POINTL   ptl;
   USHORT   i, j, usPoints;
   BOOL     bFound;

   CalcRects (hwnd, arclScore, aarclRects);
   ptl.x = x;
   ptl.y = y;

   IconRect (hwnd, &rclIcon);
   if (WinPtInRect (hab, &rclIcon, &ptl) && bDouble)
      {
      WinPostMsg (hwnd, WM_COMMAND, MPFROMSHORT (IDM_NEW), 0);
      return;
      }

   bFound = FALSE;
   for (i=0; i < NUM_POINTS; i++)
      {
      /* check left */
      if (WinPtInRect (hab, &aarclRects [0] [i], &ptl))
         {
         j = 0;
         bFound = TRUE;
         break;
         }

      /* check right */
      if (WinPtInRect (hab, &aarclRects [1] [i], &ptl))
         {
         j = 1;
         bFound = TRUE;
         break;
         }
      }

   if (bFound)
      {
      if (bHit)
         {
         usPoints = Points (i);

         if (scScore [j][i].usNumHits   < NUM_HITS)
            scScore [j][i].usNumHits++;

         else if (scScore [j][i].usNumHits   >= NUM_HITS &&
             scScore [1-j][i].usNumHits < NUM_HITS)
            {
            scScore [j][i].usNumHits++;
            scScore [j][i].usScore += usPoints;
            usScore [j] += usPoints;
            WinInvalidateRect (hwnd, arclScore + j, FALSE);
            }
         }
      else
         {
         if (scScore [j][i].usNumHits)
            scScore [j][i].usNumHits--;
         usPoints = Points (i);

         if (scScore [j][i].usNumHits >= NUM_HITS)
            {
            scScore [j][i].usScore -= usPoints;
            usScore [j] -= usPoints;
            WinInvalidateRect (hwnd, arclScore + j, FALSE);
            }
         }
      WinInvalidateRect (hwnd, aarclRects [j] + i, FALSE);
      }
   }


MRESULT EXPENTRY NewGameProc (HWND   hwnd,
                              USHORT usMessage,
                              MPARAM mp1,
                              MPARAM mp2)
   {
   switch (usMessage)
      {
      case WM_INITDLG:
         WinSetDlgItemText (hwnd, DID_LEFT, szPlayers [0]);
         WinSetDlgItemText (hwnd, DID_RIGHT, szPlayers [1]);
         break;

      case WM_COMMAND:
         switch (SHORT1FROMMP (mp1))
            {
            case DID_OK:
               WinQueryDlgItemText (hwnd, DID_LEFT, sizeof szPlayers [0], szPlayers [0]);
               WinQueryDlgItemText (hwnd, DID_RIGHT, sizeof szPlayers [1], szPlayers [1]);
               WinDismissDlg (hwnd, TRUE);
               InitScore ();
               break;

            case DID_CANCEL:
               WinDismissDlg (hwnd, FALSE);
               break;

            } /* switch (SHORT1FROMMP (mp1)) */
         break;
      }
   return WinDefDlgProc (hwnd, usMessage, mp1, mp2);
   }


MRESULT EXPENTRY OptionsProc (HWND   hwnd,
                              USHORT usMessage,
                              MPARAM mp1,
                              MPARAM mp2)
   {
   switch (usMessage)
      {
      case WM_INITDLG:
         WinEnableWindow (WinWindowFromID (hwnd, DID_301), FALSE);
         WinEnableWindow (WinWindowFromID (hwnd, DID_START_SCORE), FALSE);
         WinEnableWindow (WinWindowFromID (hwnd, DID_START_DOUBLE), FALSE);
         WinSendMsg (WinWindowFromID (hwnd, DID_CRICKET), BM_SETCHECK, 
                     MPFROMSHORT (1), 0);
         break;

      case WM_COMMAND:
         switch (SHORT1FROMMP (mp1))
            {
            case DID_OK:
               WinDismissDlg (hwnd, TRUE);
               InitScore ();
               break;

            case DID_CANCEL:
               WinDismissDlg (hwnd, FALSE);
               break;

            } /* switch (SHORT1FROMMP (mp1)) */
         break;
      }
   return WinDefDlgProc (hwnd, usMessage, mp1, mp2);
   }




MRESULT EXPENTRY MainWindowProc (HWND   hwnd,
                                 USHORT usMessage,
                                 MPARAM mp1,
                                 MPARAM mp2)
   {
   switch (usMessage)
      {
      case WM_CREATE:
         DoCreate (hwnd);
         InitScore ();
         WinInvalidateRect (hwnd, NULL, TRUE);
         break;

      case WM_PAINT:
         DoPaint (hwnd);
         return 0L;
         break;

      case WM_SIZE:
         WinInvalidateRect (hwnd, NULL, TRUE);
         break;

      case WM_BUTTON1DOWN:
      case WM_BUTTON2DOWN:
      case WM_BUTTON1DBLCLK:
      case WM_BUTTON2DBLCLK:
         DoMouse (hwnd, SHORT1FROMMP (mp1), SHORT2FROMMP (mp1),
                  usMessage == WM_BUTTON1DBLCLK ||
                  usMessage == WM_BUTTON1DOWN,
                  usMessage == WM_BUTTON1DBLCLK);
         break;

      case WM_CLOSE:
         {
         SWP   swp;

         WinQueryWindowPos (WinQueryWindow (hwnd, QW_PARENT, FALSE), &swp);
         if (!(swp.fs & SWP_MINIMIZE))
            PrfWriteProfileData (HINI_USERPROFILE, szAppName, "swp", &swp, 
                                 sizeof swp);
         }
         break;

      case WM_COMMAND:
         switch (SHORT1FROMMP (mp1))
            {
            case IDM_OPTIONS:
               if (DID_OK == WinDlgBox (HWND_DESKTOP, hwnd, OptionsProc,
                                        0, SHORT1FROMMP (mp1), NULL))
                  {
                  WinInvalidateRect (hwnd, NULL, TRUE);
                  }
               break;

            case IDM_NEW:
               if (DID_OK == WinDlgBox (HWND_DESKTOP, hwnd, NewGameProc,
                                        0, SHORT1FROMMP (mp1), NULL))
                  {
                  WinInvalidateRect (hwnd, NULL, TRUE);
                  }
               break;

            case IDM_EXIT:
               DosExit (EXIT_PROCESS, 0);
               break;
            } /* switch (SHORT1FROMMP (mp1)) */
         break;
      }
   return WinDefWindowProc (hwnd, usMessage, mp1, mp2);
   }



int _cdecl main (int argc, char *argv [])
   {
   QMSG  qmsg;
   HMQ   hmq;
   ULONG flStyle;
   HWND  hwndAppFrame, hwndAppClient;
   SWP         swp;
   ULONG       i;

   flStyle = FCF_TITLEBAR | FCF_SYSMENU | FCF_SIZEBORDER |
             FCF_MINMAX | FCF_SHELLPOSITION | FCF_TASKLIST |
             FCF_MENU | FCF_ACCELTABLE | FCF_ICON;

   /* Initialize this module */
   hab = WinInitialize (0);
   if (hab == NULL)
      DosExit (EXIT_PROCESS, 0);

   hmq = WinCreateMsgQueue (hab, 10);

   if (!WinRegisterClass (hab, "x", MainWindowProc, 0, 0))
      {
      DosExit (EXIT_PROCESS, 0);
      }

   /* Create the main window, terminate on failure. */
   hwndAppFrame = WinCreateStdWindow (HWND_DESKTOP,
                                      FS_NOBYTEALIGN,
                                      &flStyle, "x", NULL,
                                      0L, 0, 1, &hwndAppClient);

   if (hwndAppFrame == NULL)
      DosExit (EXIT_PROCESS, 0);

   i = sizeof swp;
   if (PrfQueryProfileData (HINI_USERPROFILE, szAppName, "swp", &swp, &i) &&
       i == sizeof swp)
      WinSetWindowPos (hwndAppFrame, NULL, swp.x, swp.y, swp.cx, swp.cy, 
                       SWP_ACTIVATE | SWP_SHOW | SWP_MOVE | SWP_SIZE);
   else
      WinShowWindow (hwndAppFrame, TRUE);

   WinSetWindowText (hwndAppFrame, szAppName);
   /* Get and dispatch messages. */
   while (WinGetMsg (hab, &qmsg, NULL, 0, 0))
      {
      if (qmsg.hwnd != NULL)
         WinDispatchMsg (hab, &qmsg);
      }

   DosExit (EXIT_PROCESS, 0);
   return 0;
   }
