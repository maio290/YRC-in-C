# Yamaha Remote Console (C)
A simple command line tool to use some of the remote control features of Yamaha's network receivers.

## Usage

YRC can be used with command line arguments only, if you want to have a graphical interface, simply use the AV-Controller app by Yamaha or the webinterface of your receiver.

### Current Arguments

* The first argument (no - needed): __must__ be the IP address of your receiver: xxx.xxx.xxx.xxx

* __-power_on__: Turns the receiver on.

* __-power_off__: Turn the receiver off.

* __-setvol__ xxx: The volume of your receiver. This is a double represented as an integer. You can use only values between 0 and 805.
While 0 is -0.00 dB (which is pretty loud) and 805 is mute. 800 is the lowest volume possible. You can only use values which are either .00 or .50 - for example 456 would be an invalid value.

* __-input__ xxx: The input of your receiver. Example values: AV1, AV2, HDMI1, SERVER, ...

### Example Usage

./YRC 192.168.178.54 -power_on -input AV1 -setvol 450

Turns the receiver with the ip address "192.168.178.54" on, sets the input to AV1 and sets the volume to -45.00 dB. 

## Why shall I use YRC?

Well, you don't have to. It was just written in order to automate the receiver and turn it on via cron. You can actually achieve that with cURL alone, this is currely just wrapping without any awesome features. 

## What's the deal with the precompiled binary?

It's the whole program packed with cURL (libcurl) in the binary using musle - so actually just a static version of the software but gorgeous for environments like a Raspberry Pi using OpenElec.

## Misc

### Planned features

* Increasing & Decreasing Volume: Start at value xx and move to value xx with xx iterations.
* Sleep-Function: Use the built-in sleep function.

### Stuff you may want to know

* The Yamaha receivers are using XML post data
* My verison of libcurl was failing (Error 400) due to a problem with the header, I had to set the CUSTOMREQUEST to get rid of that.
* The precompiled version was compiled with libcurl 7.24.0 & arm-linux-musleabi-gcc


