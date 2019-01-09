# RpiClock

Binary clock for Raspberry Pi 480*320 display written in C++ using gtkmm-3.0
If you need to setup your display, you can use [LCD-show](https://github.com/goodtft/LCD-show) 

![ ](https://i.imgur.com/cQRJ5l5.jpg  "Binary clock on Raspberry Pi")

## Features

* Use F11 to toggle fullscreen
* Use ESC to quit
* Swipe left or right to change theme
* Clock currently supports 3 hardcoded themes
* Clock is intended to be used upside down (so that the Pi can stand with cable plugged in)

## Dependencies
gtkmm-3.0

## Compilation
	cmake . && make

## Usage
* copy the clock.desktop file to your desktop and edit the path

