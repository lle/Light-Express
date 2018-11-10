#include <Adafruit_CircuitPlayground.h>

#define FSM_BOTTOM_ID 0
#define FSM_TOP_ID 6

#define FSM_CIRCLE 0
#define FSM_FLASH 1
#define FSM_FLASH_RED 2
#define FSM_FLASH_GREEN 3
#define FSM_FLASH_BLUE 4
#define FSM_RAINBOW 5
#define FSM_FADERED 6

#define MODE_OFF 100
#define MODE_ON 101

int fsm_state = FSM_FADERED;

const uint8_t btnLeft = 4;
const uint8_t btnRight = 5;
uint8_t modeSelector = MODE_ON;

void setup() 
{
  pinMode(btnLeft, INPUT_PULLDOWN);
  pinMode(btnRight, INPUT_PULLDOWN);
  //pinMode(switchInputPin, INPUT_PULLUP);

  Serial.begin(9600); Serial.println("Start NeoPixel Flasher Unit");
  
  CircuitPlayground.begin();
  for(int j=0; j<3; j++)
  {
    uint8_t red = 0; uint8_t green = 0; uint8_t blue = 0;
    switch(j)
    {
      case 0:
        red=255; green=0; blue=0;
        break;
      case 1:
        red=128; green=128; blue=0;
        break;
      case 2:
        red=0; green=255; blue=0;
        break;
    }
    for(int i=0; i<=9; i++)
    {
      CircuitPlayground.clearPixels();  
      CircuitPlayground.setPixelColor(i, red,   green,  blue);  
      delay(50);
    }    
  }
  CircuitPlayground.clearPixels();  
  delay(500);
}

void run_LED_OFF()
{
  CircuitPlayground.clearPixels();
  delay(50);
}

void loop() 
{  
  //CHECK for DOUBLE PRESS
  if( (digitalRead(btnLeft)==HIGH || digitalRead(btnRight)==HIGH) && modeSelector==MODE_ON )
  {
    delay(50); //wait for 50ms in case the user is not quite pressing the button at the same time
    if( digitalRead(btnLeft) == HIGH && digitalRead(btnRight) == HIGH)
    {
      CircuitPlayground.clearPixels();  
      CircuitPlayground.playTone(123,150);
      modeSelector = MODE_OFF;
      while( digitalRead(btnLeft) == HIGH || digitalRead(btnRight) == HIGH )
      {
        delay(5); //wait for button release from user
      }
      delay(100); //you are not in LED OFF mode
    }
    else
    {
      //exit if-block. It is not a double press, but a single press
    }
  }


  //CHECK for SINGLE PRESS
  if( digitalRead(btnLeft) == HIGH )
  {
    modeSelector = MODE_ON;
    CircuitPlayground.playTone(440,16);
    while(digitalRead(btnLeft) == HIGH)
      delay(80); //do nothing, wait for button release
    fsm_state++;    
    if(fsm_state > FSM_TOP_ID) //then you are out of bound, go to 0 (BOTTOM_ID)
      fsm_state = FSM_BOTTOM_ID;
  }
  if( digitalRead(btnRight) == HIGH )
  {
    modeSelector = MODE_ON;
    CircuitPlayground.playTone(370,16);
    while(digitalRead(btnRight) == HIGH)
      delay(80); //do nothing, wait for button release
    fsm_state--;
    if(fsm_state < FSM_BOTTOM_ID) //then you are out of bound, go to TOP_ID
      fsm_state = FSM_TOP_ID;
  }
  
  //RUN FSM
  run_masterStateMachine( modeSelector );
}
