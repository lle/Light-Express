void run_rainbowLED()
{
  static uint32_t ts_lastUpdated = 0;
  static uint8_t colorStage = 1; // 0 is red, 1 is green, 2 is blue
  static uint8_t red = 255;
  static uint8_t green = 0;
  static uint8_t blue = 0;
 
  if(millis() - ts_lastUpdated > 5)
  {
    ts_lastUpdated = millis();

    for(int i=0; i<=9; i++)
    {
      CircuitPlayground.setPixelColor(i, red, green, blue); 
    }

    if(colorStage==0)
    {
      blue--;
      red++;
      if(red==255)
        colorStage=1;
    }
    else if(colorStage==1)
    {
      red--;
      green++;
      if(green==255)
        colorStage=2;
    }
    else if(colorStage==2)
    {
      green--;
      blue++;
      if(blue==255)
        colorStage=0;
    }
    
  }
}

