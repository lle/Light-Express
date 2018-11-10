void run_masterStateMachine(uint8_t switch_state)
{  
  //RUN FSM
  if( switch_state == MODE_ON)
  {
    switch(fsm_state)
    {
      case FSM_CIRCLE:
        run_circleAnimation();
        break;
        
      case FSM_FLASH:
        run_flashing_white_red();
        break;
  
      case FSM_FLASH_RED:
        run_flashingRedOnly();
        break;

      case FSM_FLASH_GREEN:
        run_flashingGreenOnly();
        break;

      case FSM_FLASH_BLUE:
        run_flashingBlueOnly();
        break;

      case FSM_RAINBOW:
        run_rainbowLED();
        break;

      case FSM_FADERED:
        run_redFade();
        break;

      default:
        run_LED_OFF();
    }
  }
  else
  {
    run_LED_OFF();
  }
}

