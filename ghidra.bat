@echo off
REM Open the VF3 reverse-engineering project in Ghidra GUI.
set "JAVA_HOME=C:\Program Files\Eclipse Adoptium\jdk-21.0.11.10-hotspot"
set "GHIDRA=E:\vf3-decomp\tools\ghidra_12.1.3_PUBLIC\ghidraRun.bat"
"%GHIDRA%" "E:\vf3-decomp\extract\ghidra_proj" VF3
