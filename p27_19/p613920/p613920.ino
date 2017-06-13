// author Wang Ren <iamwrm@gmail.com>
#include <Servo.h>

Servo myservo;
int obstacle;
int HongWaiPinKou;

int MyA1, MyA2;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.

    myservo.attach(4);

    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);

    MyA1 = 3;
    MyA2 = 11;
    pinMode(MyA1, OUTPUT);
    pinMode(MyA2, OUTPUT);
    HongWaiPinKou = 13;
    pinMode(HongWaiPinKou, INPUT);
    obstacle = 1;
}

// the loop function runs over and over again forever
void loop()
{
    // have obstacle -> 0   no obstacle -> 1
    Serial.print(obstacle);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(180);
    delay(3000);
    //
    long T0;
    T0 = millis();
    while (millis() < T0 + 7000)
    {
        obstacle = digitalRead(HongWaiPinKou);
        myservo.write(93);
        analogWrite(5, 250);
        analogWrite(6, 0);
        analogWrite(MyA1, 0);
        analogWrite(MyA2, 250);
        if (obstacle == 0)
        {
            break;
        }
    }
    //
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(6);
    delay(3000);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(93);
    delay(10000);
}


