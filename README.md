# ESP8266-OLED-breakout

This is a breakout game for the [ESP8266 module](http://www.areresearch.net/2018/02/the-all-you-can-possibly-want-esp8266.html)
with a 0.96" OLED display, a 4-way joystick and an 18650 battery holder.

It waits for the user to press the button before the game starts. Each time the ball leaves the screen, it prompts them to 
press the button again to continue. Once all 32 bricks have been destroyed, a 'winner!' message is displayed before the 
game restarts and the original prompt to push the button reappears. The joystick is used to move the paddle.

It can be compiled in the Arduino IDE with the ThingPulse SSD1306 library installed. The board should be set to
"Wemos D1 R1" (you must install the ESP8266 package by the ESP8266 community in the boards manager to access it).
