void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(7, INPUT);

    //---- before is just some setups ---------------

    // t[0] is for moter 1
    // 30 s real time
    Serial.print("b:");
}

// the loop function runs over and over again forever
void loop()
{
    int obstacle = 0;
    obstacle = digitalRead(7);
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
        dlay(1000000);
    }
}
