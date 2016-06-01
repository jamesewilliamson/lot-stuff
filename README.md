# lot-stuff
I am using node-red and Mosquitto MQTT broker on a Raspberry pi B jessie

it also is running PI-Hole :) 

https://pi-hole.net/


The first thing is a 4 way switch with a temp senser
its a copy paste from examples so no credits for me.. 
this use's an nodemcu 0.9 and Arduino ide to load files, other esp 8266 should work.
if you need to change pins there will be comments telling you where..see link for Pin definition functions for Arduino to esp.
https://github.com/esp8266/Arduino/blob/master/variants/nodemcu/pins_arduino.h#L37-L59 



topics "A" "B" "C" "D" are relay's 1 on 0 off
"outTopictemp"= temp
"outTopic"= Relay Board OK

dont forget the node-red flow there is an example of big timer http://flows.nodered.org/node/node-red-contrib-bigtimer
http://tech.scargill.net/big-timer/


added alternating pulse Big timer

opto triac mock up not ready for use.. needs capacitor's fuse's ect

'update i ended up useing the old relays with transistors
to up the 3v to 5v control signal. working good so far..."
![img_20160502_063255](https://cloud.githubusercontent.com/assets/8534154/14953192/1c13fd64-1035-11e6-9e7e-2196b49ab68b.jpg)
old wired 4way
(https://cloud.githubusercontent.com/assets/8534154/14953486/024bddfe-1038-11e6-9feb-65381764b2d3.jpg)

(https://cloud.githubusercontent.com/assets/8534154/14953477/e97fd500-1037-11e6-8e64-582247fb17d5.jpg)
