# lightExpress
A custom software and overkill bike light

Details here: https://www.reddit.com/r/arduino/comments/9vz3y7/very_custom_overkill_bike_light/


The overkill thing in question
Story time:
So I got to work in the morning on my Boosted Board. Then I realized I forgot my flashlight at home. The flashlight is particularly useful for the way back. The sun sets at 5PM. By the time I'm leaving work, it's super dangerous to skate without some kind of light to signal to other vehicle.

Solution
Let's build a cool animated flashlight with the Adafruit Circuit Playground Express that I just got recently.

So let's start coding some simple animation.
```
uint8_t colorStateRed = 0;
for(int i=0; i<=9; i++)
{
if(colorStateRed == 0)
CircuitPlayground.setPixelColor(i, 0, 50, 50);
else if(colorStateRed == 1)
CircuitPlayground.setPixelColor(i, 255, 0, 0);
}
```

if(colorStateRed == 0) //change color state for next update
colorStateRed = 1;
else
colorStateRed = 0;
Result of white+red animation
Alright, looking good. That should be good enough to catch drivers' attention. Now I need an enclosure. Thingiverse to the rescue. Found a good model from @schroepfer (https://www.thingiverse.com/thing:2777893)
Then it was printed on our Prusa MK3. It's a perfect fit.

Also added a small LiPo battery 3.7V 150mAh. The circuit consumes at most 50mA when the LEDs are blinking, so I believe that the device can run for a bit less than 3 hours.

![img](https://i.redd.it/9muk09m6blx11.png)

150mAh LiPo
Cut the back cover using an old piece of plastic laying around the shop.

![img](https://i.redd.it/9ft77pe7blx11.png)

Next step was to build somekind of diffuser. Well, we (the people our the shop) always wanted to try the NinjaFlex filament on the Prusa. So we did! A lot of tweaking required. (Tip: remove retraction, extruder=280C, bed=85C)

![img](https://i.redd.it/0zh1k5z8blx11.png)

good fit
Added a velcro strap to attached the device to my backpack

![img](https://i.redd.it/ftakky8ablx11.png)

So here is how it looks on my backpack.

![img](https://i.redd.it/w4z4kscbblx11.png)

Animations can be switched through the button on the board
Now that the prototype is built, I went into an Arduino spree and coded a small state machine and a few different animation.
Spinning animation
Arduino code is on Github: https://github.com/lle/lightExpress
