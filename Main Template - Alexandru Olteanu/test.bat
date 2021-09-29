@echo off
generate >input.txt
main <input.txt >output.txt
second <input.txt >second_output.txt
fc output.txt second_output.txt
if errorlevel 1 exit
test
