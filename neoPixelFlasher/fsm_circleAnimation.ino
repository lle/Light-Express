void run_circleAnimation()
{
  static uint8_t led1_counterIndex=0;
  static uint8_t led2_counterIndex=5;
  static uint32_t ts_lastUpdated = 0;

  if(millis() - ts_lastUpdated > 50)  //run every X amount of time
  {
    ts_lastUpdated = millis();
    
    /****************MOVING LED 1 *******************/
    //set current LED to white
    CircuitPlayground.setPixelColor(led1_counterIndex, 255,   255,   255);  
  
    //increment for next update
    led1_counterIndex++;
    if(led1_counterIndex==10) //if the counter goes beyond the # of LED, then reset to 0
      led1_counterIndex=0;
    
    //set next LED to be a different color
    CircuitPlayground.setPixelColor(led1_counterIndex, 255,   0,   0);  
   
  
    /****************MOVING LED 2 *******************/
    //set current LED to white
    CircuitPlayground.setPixelColor(led2_counterIndex, 255,   255,   255); 
  
    //increment for next update
    led2_counterIndex++;
    if(led2_counterIndex==10) //if the counter goes beyond the # of LED, then reset to 0
      led2_counterIndex=0;
  
    //set next LED to be a different color
    CircuitPlayground.setPixelColor(led2_counterIndex, 255,   0,   0);  
  }
  
}
