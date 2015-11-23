# About

rcswitch-pi is for controlling rc remote controlled power sockets 
with the raspberry pi. Kudos to the projects [rc-switch](http://code.google.com/p/rc-switch)
and [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi).

This programm is basically the same as the original rcswitch-pi, except for the fact that you will now be able to send binaries and hexadecimal codes with the original send.cpp file.


## Usage

First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
After that you can compile the example program *send* by executing *make*. 
You may want to changet the used GPIO pin before compilation in the send.cpp source file.
