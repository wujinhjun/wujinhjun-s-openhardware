/*
 * @Author: wujinhjun 
 * @Date: 2022-02-07 13:04:06 
 * @Last Modified by: wujinhjun
 * @Last Modified time: 2022-02-07 13:04:51
 */
#include <PS2X_lib.h>  //for v1.6
#include <Adafruit_MS_PWMServoDriver.h>

#define PS2_DAT        12  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        13  //17

//#define pressures   true
 #define pressures   false
// #define rumble      true
#define rumble      false

Adafruit_MS_PWMServoDriver pwm = Adafruit_MS_PWMServoDriver(0x60);
PS2X ps2x; // create PS2 Controller Class

int error = 0;
byte type = 0;
byte vibrate = 0;

String item;
int maxSpeed = 2550;
int num;

//左前轮，接M1
#define wheelLeftFrontGo 9 
#define wheelLeftFrontBack 8 

//左后轮，接M4
#define wheelLeftRearGo 12 
#define wheelLeftRearBack 13 

//右前轮，接M2
#define wheelRightFrontGo  10 
#define wheelRightFrontBack  11 

//右后轮，接M3
#define wheelRightRearGO  15 
#define wheelRightRearBack  14 
//有一说一，这个拓展版不太行，不符合强迫症的布线原则

void go()
{
    pwm.setPWM(wheelLeftFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, maxSpeed);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void back()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, maxSpeed);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, maxSpeed);
}

void left()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelLeftRearGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, maxSpeed);
}

void right()
{
    pwm.setPWM(wheelLeftFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, maxSpeed);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelRightRearGO, 0, maxSpeed);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void goLeft()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void goRight()
{
    pwm.setPWM(wheelLeftFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, maxSpeed);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void backLeft()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, maxSpeed);
}

void backRight()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, maxSpeed);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void spinClockWise()
{
    pwm.setPWM(wheelLeftFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, maxSpeed);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, maxSpeed);
}

void spinAntiClockWise()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, maxSpeed);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, maxSpeed);

    pwm.setPWM(wheelRightFrontGo, 0, maxSpeed);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, maxSpeed);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void stop()
{
    pwm.setPWM(wheelLeftFrontGo, 0, 0);
    pwm.setPWM(wheelLeftFrontBack, 0, 0);

    pwm.setPWM(wheelLeftRearGo, 0, 0);
    pwm.setPWM(wheelLeftRearBack, 0, 0);

    pwm.setPWM(wheelRightFrontGo, 0, 0);
    pwm.setPWM(wheelRightFrontBack, 0, 0);

    pwm.setPWM(wheelRightRearGO, 0, 0);
    pwm.setPWM(wheelRightRearBack, 0, 0);
}

void setup(){
 
  Serial.begin(9600);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  pwm.begin();
  pwm.setPWMFreq(50);  
  for (uint8_t i = 0; i < 16; i++){
      pwm.setPWM(i, 0, 0);
  }
}

void loop() {
    ps2x.read_gamepad(false, vibrate); 
        
    if(ps2x.Button(PSB_PAD_UP)) {      
        go();
        num = 0;
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
        right();
        num = 0;
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
        left();
        num = 0;
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
        back();
        num = 0;
    }   
    if(ps2x.ButtonPressed(PSB_CIRCLE)){               
        goLeft();
        num = 0;
    }
    if(ps2x.NewButtonState(PSB_CROSS)){               
        backLeft();
        num = 0;
    }
    if(ps2x.ButtonReleased(PSB_SQUARE)){              
        goRight();
        num = 0;
    }
    if(ps2x.ButtonReleased(PSB_TRIANGLE)){           
        backRight();
        num = 0;
    }
    if(ps2x.Button(PSB_L2)){
        spinClockWise();
        num = 0;
    }
    if(ps2x.Button(PSB_R2)){
        spinAntiClockWise(); 
        num = 0;
    }

    if(ps2x.Button(PSB_L3)){
        stop();
    }
    if(ps2x.Button(PSB_R3)){
        stop();
    }
    delay(10);
    num = num +1;
    if (num > 36){
        stop();
    }  
}
