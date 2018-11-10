void run_flashingRedOnly()
{
  static uint8_t colorStateRed = 0;
  static uint32_t ts_lastUpdated = 0;

  if(millis() - ts_lastUpdated > 200)
  {
    ts_lastUpdated = millis();
    
    for(int i=0; i<=9; i++)
    {
      if(colorStateRed == 0)
        CircuitPlayground.setPixelColor(i, 0,   50,   50); 
      else if(colorStateRed == 1)
        CircuitPlayground.setPixelColor(i, 255,   0,   0); 
    }
    //change color state for next update
    if(colorStateRed == 0)
      colorStateRed = 1;
    else
      colorStateRed = 0;
  }
}
