
echo.        * CmpSJACanDrvItf.m4 ... CmpSJACanDrvItf.h 

copy ..\CmpSJACanDrvItf.m4 CmpSJACanDrvItf__.m4
..\..\BuildUtils\msys\bin\dos2unix CmpSJACanDrvItf__.m4

%2\m4 -I%3 Exports.m4 - < %1__.m4 > %1.h
..\..\BuildUtils\msys\bin\m4 -I../../BuildUtils/M4Defs Exports.m4 - < "CmpSJACanDrvItf__.m4" > ..\CmpSJACanDrvItf.h
..\..\BuildUtils\msys\bin\dos2unix ..\CmpSJACanDrvItf.h
..\..\BuildUtils\msys\bin\unix2dos ..\CmpSJACanDrvItf.h
del "CmpSJACanDrvItf__.m4"
pause
