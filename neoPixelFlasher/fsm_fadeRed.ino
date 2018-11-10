void run_redFade()
{
  static uint32_t ts_lastUpdated = 0;
  static uint8_t colorStage = 1; 
  static uint8_t red = 255;

 
  if(millis() - ts_lastUpdated > 2)
  {
    ts_lastUpdated = millis();

    for(int i=0; i<=9; i++)
    {
      CircuitPlayground.setPixelColor(i, red, 0, 0); 
    }

    if(colorStage==0)
    {
      red++;
      if(red==255)
        colorStage=1;
    }
    else if(colorStage==1)
    {
      red--;
      if(red==0)
        colorStage=0;
    }
    
  }
}

