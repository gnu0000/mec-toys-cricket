# Microsoft Developer Studio Generated NMAKE File, Based on cricket.dsp
!IF "$(CFG)" == ""
CFG=cricket - Win32 Debug
!MESSAGE No configuration specified. Defaulting to cricket - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "cricket - Win32 Release" && "$(CFG)" !=\
 "cricket - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cricket.mak" CFG="cricket - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cricket - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "cricket - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cricket - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\cricket.exe"

!ELSE 

ALL : "$(OUTDIR)\cricket.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\cNewDlg.obj"
	-@erase "$(INTDIR)\cricket.obj"
	-@erase "$(INTDIR)\cricket.pch"
	-@erase "$(INTDIR)\cricket.res"
	-@erase "$(INTDIR)\cricketDoc.obj"
	-@erase "$(INTDIR)\cricketView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\cricket.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\cricket.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\cricket.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cricket.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\cricket.pdb" /machine:I386 /out:"$(OUTDIR)\cricket.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cNewDlg.obj" \
	"$(INTDIR)\cricket.obj" \
	"$(INTDIR)\cricket.res" \
	"$(INTDIR)\cricketDoc.obj" \
	"$(INTDIR)\cricketView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\cricket.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\cricket.exe" "$(OUTDIR)\cricket.bsc"

!ELSE 

ALL : "$(OUTDIR)\cricket.exe" "$(OUTDIR)\cricket.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\cNewDlg.obj"
	-@erase "$(INTDIR)\cNewDlg.sbr"
	-@erase "$(INTDIR)\cricket.obj"
	-@erase "$(INTDIR)\cricket.pch"
	-@erase "$(INTDIR)\cricket.res"
	-@erase "$(INTDIR)\cricket.sbr"
	-@erase "$(INTDIR)\cricketDoc.obj"
	-@erase "$(INTDIR)\cricketDoc.sbr"
	-@erase "$(INTDIR)\cricketView.obj"
	-@erase "$(INTDIR)\cricketView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\cricket.bsc"
	-@erase "$(OUTDIR)\cricket.exe"
	-@erase "$(OUTDIR)\cricket.ilk"
	-@erase "$(OUTDIR)\cricket.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\cricket.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\cricket.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cricket.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\cNewDlg.sbr" \
	"$(INTDIR)\cricket.sbr" \
	"$(INTDIR)\cricketDoc.sbr" \
	"$(INTDIR)\cricketView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\cricket.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\cricket.pdb" /debug /machine:I386 /out:"$(OUTDIR)\cricket.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\cNewDlg.obj" \
	"$(INTDIR)\cricket.obj" \
	"$(INTDIR)\cricket.res" \
	"$(INTDIR)\cricketDoc.obj" \
	"$(INTDIR)\cricketView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\cricket.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "cricket - Win32 Release" || "$(CFG)" ==\
 "cricket - Win32 Debug"
SOURCE=.\cNewDlg.cpp
DEP_CPP_CNEWD=\
	".\cNewDlg.h"\
	".\cricket.h"\
	

!IF  "$(CFG)" == "cricket - Win32 Release"


"$(INTDIR)\cNewDlg.obj" : $(SOURCE) $(DEP_CPP_CNEWD) "$(INTDIR)"\
 "$(INTDIR)\cricket.pch"


!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"


"$(INTDIR)\cNewDlg.obj"	"$(INTDIR)\cNewDlg.sbr" : $(SOURCE) $(DEP_CPP_CNEWD)\
 "$(INTDIR)" "$(INTDIR)\cricket.pch"


!ENDIF 

SOURCE=.\cricket.cpp

!IF  "$(CFG)" == "cricket - Win32 Release"

DEP_CPP_CRICK=\
	".\cricket.h"\
	".\cricketDoc.h"\
	".\cricketView.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\cricket.obj" : $(SOURCE) $(DEP_CPP_CRICK) "$(INTDIR)"\
 "$(INTDIR)\cricket.pch"


!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"

DEP_CPP_CRICK=\
	".\cricket.h"\
	".\cricketDoc.h"\
	".\cricketView.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\cricket.obj"	"$(INTDIR)\cricket.sbr" : $(SOURCE) $(DEP_CPP_CRICK)\
 "$(INTDIR)" "$(INTDIR)\cricket.pch"


!ENDIF 

SOURCE=.\cricket.rc
DEP_RSC_CRICKE=\
	".\res\cricket.ico"\
	".\res\cricket.rc2"\
	".\res\cricketDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\cricket.res" : $(SOURCE) $(DEP_RSC_CRICKE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\cricketDoc.cpp

!IF  "$(CFG)" == "cricket - Win32 Release"

DEP_CPP_CRICKET=\
	".\cNewDlg.h"\
	".\cricket.h"\
	".\cricketDoc.h"\
	

"$(INTDIR)\cricketDoc.obj" : $(SOURCE) $(DEP_CPP_CRICKET) "$(INTDIR)"\
 "$(INTDIR)\cricket.pch"


!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"

DEP_CPP_CRICKET=\
	".\cNewDlg.h"\
	".\cricket.h"\
	".\cricketDoc.h"\
	

"$(INTDIR)\cricketDoc.obj"	"$(INTDIR)\cricketDoc.sbr" : $(SOURCE)\
 $(DEP_CPP_CRICKET) "$(INTDIR)" "$(INTDIR)\cricket.pch"


!ENDIF 

SOURCE=.\cricketView.cpp

!IF  "$(CFG)" == "cricket - Win32 Release"

DEP_CPP_CRICKETV=\
	".\cricket.h"\
	".\cricketDoc.h"\
	".\cricketView.h"\
	

"$(INTDIR)\cricketView.obj" : $(SOURCE) $(DEP_CPP_CRICKETV) "$(INTDIR)"\
 "$(INTDIR)\cricket.pch"


!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"

DEP_CPP_CRICKETV=\
	".\cricket.h"\
	".\cricketDoc.h"\
	".\cricketView.h"\
	

"$(INTDIR)\cricketView.obj"	"$(INTDIR)\cricketView.sbr" : $(SOURCE)\
 $(DEP_CPP_CRICKETV) "$(INTDIR)" "$(INTDIR)\cricket.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "cricket - Win32 Release"

DEP_CPP_MAINF=\
	".\cricket.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\cricket.pch"


!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"

DEP_CPP_MAINF=\
	".\cricket.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)" "$(INTDIR)\cricket.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "cricket - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\cricket.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\cricket.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "cricket - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\cricket.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\cricket.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

