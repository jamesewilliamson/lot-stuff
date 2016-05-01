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
