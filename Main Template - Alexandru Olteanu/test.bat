@echo off
generate >input.txt
main <input.txt >output.txt
stupid <input.txt >stupid_output.txt
fc output.txt stupid_output.txt
if errorlevel 1 exit
test
