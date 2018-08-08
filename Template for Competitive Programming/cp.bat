@echo off
SET name=%1%

cd %name%
call g++ %name%.cpp -o %name%

call %name%.exe>..\out.txt
cd ..