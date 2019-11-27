# PrusaBoxCode
Code for my Prusa i3 Mk3s Box with Ikea lack. i'm following ["How to build a simplee nclosure for your 3D printer](https://blog.prusaprinters.org/cheap-simple-3d-printer-enclosure/)

## Materials
* [Raspberry Pi 3 Model B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/)
* [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3)
* [leds ws2811](https://www.amazon.fr/gp/product/B01CNL6LLA/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1) 
* [TP-Link HS100](https://www.tp-link.com/fr/home-networking/smart-plug/hs110/)
* [http://shd-detecteurs.com/index.php?id=43](http://shd-detecteurs.com/index.php?id=43)
## OctoPi Need

### GoPro-Py-Api:
Api python [Here](https://github.com/KonradIT/gopro-py-api)

### OctoLapse-GoPro: 
Use GoPro with Octolapse [Here](https://github.com/yet-another-average-joe/OctoLapse-GoPro)

### tplink-smartplug
https://github.com/softScheck/tplink-smartplug

turn on 
```bash
 python /home/pi/tplink-smartplug-master/tplink_smartplug.py -t 192.168.1.37 -c on
```
turn off
```bash
 python /home/pi/tplink-smartplug-master/tplink_smartplug.py -t 192.168.1.37 -c off
```
## OctoPi Plugins
* [Octolapse](https://plugins.octoprint.org/plugins/octolapse/)
