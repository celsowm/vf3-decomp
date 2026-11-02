@echo off
rem The build's CMAKE_C_COMPILER (E:/vf3-decomp/gcc_wrapper.bat) points here.
rem Forward every argument to the ucrt64 GCC; the output file carries the
rem .obj name by convention (CMAKE passes it explicitly).
C:\msys64\ucrt64\bin\gcc.exe %*
exit /b %ERRORLEVEL%
