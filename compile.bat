cls

SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config

rem ------------------------------------------------------------------------------------------

zcc +zx -v -c -clib=new --fsigned-char -o objects.o @enemyList.lst

rem exit /b

zcc +zx -m  -startup=5 -clib=new objects.o @ramMAIN.lst -pragma-include:zpragma.inc  -o output

rem 32 column mode
rem zcc +zx -m  -startup=1 -clib=new objects.o @ramMAIN.lst -pragma-include:zpragma.inc  -o output

rem ------------------------------------------------------------------------------------------


move "output_CODE.bin" basic
move "output_UNASSIGNED.bin" basic
move "output_UNCONTENDED_enemy_locations.bin" basic
cd basic


appmake +zx -b output_CODE.bin -o code.tap --org 32768 --noloader --blockname code

appmake +zx -b output_UNCONTENDED_enemy_locations.bin -o data.tap --org 63488 --noloader --blockname edata




cd utils
	copy "bas2tap.exe" "..\"
cd ..

	bas2tap -a10 -sBASIC loader.bas basloader.tap


copy /b basloader.tap + code.tap + data.tap 1output.tap


move "1output.tap" "..\"

del "basloader.tap"
del "code.tap"
del "data.tap"

del "output_CODE.bin"
del "output_UNASSIGNED.bin"
del "output_UNCONTENDED_enemy_locations.bin"


cd ..

del "objects.o"

call beep.bat