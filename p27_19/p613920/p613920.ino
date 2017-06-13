// author Wang Ren <iamwrm@gmail.com>
#include <Servo.h>

Servo myservo;
int obstacle;
int HongWaiPinKou;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.

    myservo.attach(3);
    HongWaiPinKou = 13;

    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);

    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
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
    analogWrite(A1, 0);
    analogWrite(A2, 0);
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
        analogWrite(A1, 0);
        analogWrite(A2, 250);
        if (obstacle == 0)
        {
            break;
        }
    }
    //
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    myservo.write(6);
    delay(3000);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    myservo.write(93);
    delay(10000);
}

