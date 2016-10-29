lightwaverf-pi
==============

This code is a port of the excellent [lightwaverf arduino library](https://github.com/lawrie/LightwaveRF) written by Lawrie Griffiths to the Raspberry Pi. It utilises the [WiringPi](http://wiringpi.com/) library to do most of the GPIO work. 

To use this library you will need a 433 Mhz transmitter and/or receiver attached to your Pi. The default is to pin 1 and 0 respectivly (wiring pi pin numbers not the actual processor numbers, see [http://wiringpi.com/pins/]). If you want to use different pin numbers these can be set in the call to lw_setup().

To compile the code you will need wiring pi installed. Instructions can be found [here](http://wiringpi.com/download-and-install/). <br/>
<h2>To install lightwaverf-pi:</h2>
1. Install WiringPi by following the instructions [here](http://wiringpi.com/download-and-install/).
2. Browse to your users home directory, e.g. `cd /home/pi/`
3. Clone the lightwaverf-pi project by using `git clone https://github.com/leachj/lightwaverf-pi.git` this will then put the files in `/home/pi/lightwaverf-pi`</li>
4. Go to the created directory `cd /home/pi/lightwaverf-pi`
5. Run `make` followed by `sudo make install` this will build the library and two example programs: send and receive.

<h2>To setup a new device:</h2>
1. Browse to the directory where the lightwaverf-pi project is installed `cd /home/pi/lightwaverf-pi`</li>
2. Put the LightWaveRF device into pairing mode (normally hold a blue button or hold both buttons on a wall dimmer).</li>
3. <b>If you have only one device</b> on your network using the `./send 1` command. This will assign the LightWaveRF device the ID "F296D1" unit 2.</li>
4. <b>If you have multiple devices</b> or want to specify the device ID, use the command `./send F296C0 3 1`
* Where F296C0 is the ID that you want to assign</li>
* Where 3 is the unit, this would equate to button 2 if you use a lightwave handheld remote control</li>
* Where 1 is the signal for on, this could be 0 for setting up purposes</li>

<h2>Usage</h2>
`send <0,1>` will send either a off or on signal to device F296D1 unit 2. 

`send F296C0 3 <0,1>` will send either off or on to device F296C0 unit 3.

`receive` will print out all of the code it receives. 

These command will also make the library available for other programs to use with the .so files in /usr/local/lib and the lightwaverf.h file into /usr/local/include



