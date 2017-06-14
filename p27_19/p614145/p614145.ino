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
    delay(3000);
    //
    long T0;
    T0 = millis();
    while (millis() < T0 + 7000)
    {
        obstacle = digitalRead(HongWaiPinKou);
        myservo.write(93);
        // youbian
        int MaxSpeed1, MaxSpeed2;
        MaxSpeed1 = 199;
        MaxSpeed2 = 200;

        double co1, co2;
        co1 = 1;
        if (millis() < T0 + 1500)
        {
            co1 = (double)(millis() - T0) / 1500.0;
        }
        if (millis() > T0 + 7000 - 1500)
        {
            co1 = (double)(T0 + 7000 - millis() ) / 1500.0;
        }

        Serial.print(((int)MaxSpeed1 * co1));
        Serial.print("\n");
        analogWrite(5, ((int)MaxSpeed1 * co1));
        analogWrite(6, 0);
        analogWrite(MyA1, 0);
        analogWrite(MyA2, ((int)MaxSpeed2 * co1));
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
    delay(3000);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(MyA1, 0);
    analogWrite(MyA2, 0);
    myservo.write(93);
    delay(10000);
}

