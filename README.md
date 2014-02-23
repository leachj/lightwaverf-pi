lightwaverf-pi
==============

This code is a port of the excellent [lightwaverf arduino library](https://github.com/lawrie/LightwaveRF) written by Lawrie Griffiths to the Raspberry Pi. It utilises the [WiringPi](http://wiringpi.com/) library to do most of the GPIO work. 

To use this library you will need a 433 Mhz transmitter and/or receiver attached to your Pi. The default is to pin 1 and 0 respectivly (wiring pi pin numbers not the actual processor numbers, see [http://wiringpi.com/pins/]). If you want to use different pin numbers these can be set in teh call to lw_setup().

To compile the code you will need wiring pi installed. Instructions can be found [here](http://wiringpi.com/download-and-install/). When this innstalled run `make` followed by `sudo make install` this will build the library and two example programs: send and receive. `send <0,1>` will send either a off or on signal the the code specified on the send.cpp file. `receive` will print out all of the code it receives. These command will also make the library available for other programs to use with the .so files in /usr/local/lib and the lightwaverf.h file into /usr/local/include

