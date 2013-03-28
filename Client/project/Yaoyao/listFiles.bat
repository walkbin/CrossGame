@echo off 
set work_path=E:\Richie\source\CrossGame\Client\project\Yaoyao\Classes
E: 
;cd %work_path% 
for /R ".\" %%s in (*.cpp *.c) do ( 
echo %%s >> filelist.txt 
) 
pause 