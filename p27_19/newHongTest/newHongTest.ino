
// author Wang Ren <iamwrm@gmail.com>
#include <Servo.h>

Servo myservo;

int started_F, pulled_F, gone_F, relieved_F;
long t0;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.

    myservo.attach(A5);

    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);

    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
    int obstacle = 0;
    obstacle = digitalRead(13);
    // have obstacle -> 0   no obstacle -> 1
    //  Serial.print(obstacle);

    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 0);
    myservo.write(180);
    delay(3000);
    //

    myservo.write(93);
    analogWrite(A1, 250);
    analogWrite(A2, 0);
    analogWrite(A3, 250);
    analogWrite(A4, 0);
    delay(3000);
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

