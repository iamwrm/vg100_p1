// author Wang Ren <iamwrm@gmail.com>
#include <Servo.h>

Servo myservo;
int obstacle;
int HongWaiPinKou;

int MyA1, MyA2;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
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

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(180);
    int mydelay;
    mydelay = 3000;
    delay(mydelay);
    //
    long T0;
    T0 = millis();

    double acc_time,dcc_time;
    acc_time = 1000.0;
    dcc_time = 1000.0;
    int TotalTime = acc_time + dcc_time;

    while (millis() < T0 + TotalTime)
    {
        obstacle = digitalRead(HongWaiPinKou);
        myservo.write(93);
        // youbian
        int MaxSpeed1, MaxSpeed2;
        // you 1 // zuo 2

        MaxSpeed1 = (int)(199.0 / 1.5);
        MaxSpeed2 = (int)(194.0 / 1.5);

        double co1, co2;
        co1 = 1;
        if (millis() < T0 + (int)acc_time)
        {
            co1 = (double)(millis() - T0) / acc_time;
        }
        if (millis() < T0 + (int)acc_time)
        {
            co2 = (double)(millis() - T0) / acc_time;
        }
        if (millis() > T0 + TotalTime - (int)dcc_time)
        {
            co1 = (double)(T0 + TotalTime - millis()) / dcc_time;
        }
        if (millis() > T0 + TotalTime - (int)dcc_time)
        {
            co2 = (double)(T0 + TotalTime - millis()) / dcc_time;
        }

        Serial.print(((int)MaxSpeed1 * co1));
        Serial.print("\n");
        // you
        analogWrite(5, ((int)MaxSpeed1 * co1));
        analogWrite(6, 0);
        //zuo
        analogWrite(MyA1, 0);
        analogWrite(MyA2, ((int)MaxSpeed2 * co2));
        /*
        if (obstacle == 0)
        {
            break;
        }
        */
    }
    //
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(6);
    delay(mydelay-200);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(93);
    delay(10000);
}

