#include <Adafruit_MS_PWMServoDriver.h>

Adafruit_MS_PWMServoDriver pwm = Adafruit_MS_PWMServoDriver(0x60);

String items;
int maxSpeed = 2550;
int num = 0;
//左前轮，接M1
#define wheelLeftFrontGo 9
#define wheelLeftFrontBack 8

//左后轮，接M4
#define wheelLeftRearGo 12
#define wheelLeftRearBack 13

//右前轮，接M2
#define wheelRightFrontGo 10
#define wheelRightFrontBack 11

//右后轮，接M3
#define wheelRightRearGO 15
#define wheelRightRearBack 14
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

void stopCar()
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

//void run(String items)
//{
//    if(String(items).equals(String("GO"))){
//        go();
//    }
//    if(String(items).equals(String("BACK"))){
//        back();
//    }
//    if(String(items).equals(String("LEFT"))){
//        left();
//    }
//    if(String(items).equals(String("RIGHT"))){
//        right();
//    }
//    if(String(items).equals(String("GL"))){
//        goLeft();
//    }
//    if(String(items).equals(String("GR"))){
//        goRight();
//    }
//    if(String(items).equals(String("BL"))){
//        backLeft();
//    }
//    if(String(items).equals(String("BR"))){
//        backRight();
//    }
//    if(String(items).equals(String("SCW"))){
//        spinClockWise();
//    }
//    if(String(items).equals(String("SACW"))){
//        spinAntiClockWise();
//    }
//}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
  for (uint8_t i = 0; i < 16; i++){
      pwm.setPWM(i, 0, 0);
  }
}

void loop() {
    if(Serial.available() > 0){
        items = Serial.readStringUntil('a');
        if(String(items).equals(String("GO"))) {      
            go();
            num = 0;
        }
        if(String(items).equals(String("RIGHT"))){
            right();
            num = 0;
        }
        if(String(items).equals(String("LEFT"))){
            left();
            num = 0;
        }
        if(String(items).equals(String("BACK"))){
            back();
            num = 0;
        }   
        if(String(items).equals(String("GL"))){               
            goLeft();
            num = 0;
        }
        if(String(items).equals(String("BL"))){               
            backLeft();
            num = 0;
        }
        if(String(items).equals(String("GR"))){              
            goRight();
            num = 0;
        }
        if(String(items).equals(String("BR"))){           
            backRight();
            num = 0;
        }
        if(String(items).equals(String("SCW"))){
            spinClockWise();
            num = 0;
        }
        if(String(items).equals(String("SACW"))){
            spinAntiClockWise(); 
            num = 0;
        }

        if(String(items).equals(String("STOP"))){
            stopCar();
        }
    }
    delay(10);
    num = num +1;
    if (num > 50){
        stopCar();
    }
}
