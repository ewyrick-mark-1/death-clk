# death-clk

eek!

C project running on a rasberry pi 0 w (v1.1) running Rasberry Pi OS Lite. Communicates with a 16x2 Character oled IC module (SEH1602-A) to display a countdown (in seconds) until a specified date.

external libraries:
- lgpio.h : comes standard with pios, install dev headers via sudo apt install liblgpio-dev

setup:
1. create a .env file, copying the format in .env.example
2. fill out .env file with desired values
3. run "make" from project directory
4. cd into build and run "./death-clk"  
