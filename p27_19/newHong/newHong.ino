
// author Wang Ren <iamwrm@gmail.com>
#include <servo.h>

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

    started_F = 0;
    pulled_F = 0;
    gone_F = 0;
    relieved_F = 0;
}

// the loop function runs over and over again forever
void loop()
{
    int obstacle = 0;
    obstacle = digitalRead(13);
    // have obstacle -> 0   no obstacle -> 1
    Serial.print(obstacle);

    if (started_F)
    {
        // 拉舵机
        t0 = millis();
        while (millis() < t0 + 4800)
        {
            analogWrite(A1, 0);
            analogWrite(A2, 0);
            analogWrite(A3, 0);
            analogWrite(A4, 0);

            myservo.write(180);
        }
        pulled_F = 1;
        started_F = 0;
    }

    if (pulled_F)
    {
        // 走
        // hongwai
        // 缓慢减速
        t0 = millis();
        while (millis() < t0 + 5 * 1000)
        {
            myservo.write(93);
            analogWrite(A1, 250);
            analogWrite(A2, 0);
            analogWrite(A3, 250);
            analogWrite(A4, 0);
            if (obstacle == 0)
            {
                break;
            }
        }
        gone_F = 1;
        pulled_F = 0;
    }
    if (gone_F)
    {
        // 放
        t0 = millis();
        while (millis() < t0 + 3 * 1000)
        {
            analogWrite(A1, 0);
            analogWrite(A2, 0);
            analogWrite(A3, 0);
            analogWrite(A4, 0);
            myservo.write(6);
        }
        relieved_F = 1;
        gone_F = 0;
    }
    if (gone_F)
    {
        delay(100000);
    }
}
