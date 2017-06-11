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

    //---- before is just some setups ---------------

    // t[0] is for moter 1
    // 30 s real time
    Serial.print("b:");
}

// the loop function runs over and over again forever
void loop()
{
    //  analogWrite(9,200 );
    //  analogWrite(10,200 );
    int obstacle = 0;
    obstacle = digitalRead(13);
    // have obstacle -> 0   on obstacle -> 1
    Serial.print(obstacle);

    int started_F, pulled_F, gone_F, relieved_F;
    started_F = 0;
    pulled_F = 0;
    gone_F = 0;
    relieved_F = 0;

    if (started_F)
    {
        // 拉电机
        pulled_F = 1;
        started_F = 0;
    }

    if (pulled_F)
    {
        // 走
        gone_F = 1;
        pulled_F = 0;
    }
    if (gone_F)
    {
        // 放
        relieved_F = 1;
        gone_F = 0;
    }
    if (gone_F)
    {
        delay(100000);
    }
}
