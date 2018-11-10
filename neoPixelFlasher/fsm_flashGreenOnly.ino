void run_flashingGreenOnly()
{
  static uint8_t colorState = 0;
  static uint32_t ts_lastUpdated = 0;

  if(millis() - ts_lastUpdated > 200)
  {
    ts_lastUpdated = millis();
    
    for(int i=0; i<=9; i++)
    {
      if(colorState == 0)
        CircuitPlayground.setPixelColor(i, 50,   0,   50); 
      else if(colorState == 1)
        CircuitPlayground.setPixelColor(i, 0,   255,   0); 
    }
    //change color state for next update
    if(colorState == 0)
      colorState = 1;
    else
      colorState = 0;
  }
}


