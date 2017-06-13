// author Wang Ren <iamwrm@gmail.com>
#include <Servo.h>

Servo myservo;
int obstacle;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.

    myservo.attach(A5);

    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);

    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(10, INPUT);
    obstacle = 1;
}

// the loop function runs over and over again forever
void loop()
{
    // have obstacle -> 0   no obstacle -> 1
    Serial.print(obstacle);

    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 0);
    myservo.write(180);
    delay(3000);
    //
    long long T0;
    T0 = millis();
    while (millis() < T0 + 7000)
    {
        obstacle = digitalRead(10);
        myservo.write(93);
        analogWrite(A1, 250);
        analogWrite(A2, 0);
        analogWrite(A3, 0);
        analogWrite(A4, 250);
        if (obstacle == 0)
        {
            break;
        }
    }
    //
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 0);
    myservo.write(6);
    delay(3000);

    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 0);
    myservo.write(93);
    delay(10000);
}