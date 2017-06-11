// author Wang Ren <iamwrm@gmail.com>
int started_F, pulled_F, gone_F, relieved_F;
long t0;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(13, INPUT);

    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);

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
    // have obstacle -> 0   on obstacle -> 1
    Serial.print(obstacle);

    int dianJiPin = 10;
    int duoJiPin = 9;

    if (started_F)
    {
        // 拉舵机
        t0 = millis();
        while (millis() < t0 + 3 * 1000)
        {
            analogWrite(duoJiPin, 100);
        }
        pulled_F = 1;
        started_F = 0;
    }

    if (pulled_F)
    {
        // 走
        t0 = millis();
        while (millis() < t0 + 3 * 1000)
        {
            analogWrite(dianJiPin, 100);
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
            analogWrite(duoJiPin, -100);
        }
        relieved_F = 1;
        gone_F = 0;
    }
    if (gone_F)
    {
        delay(100000);
    }
}
