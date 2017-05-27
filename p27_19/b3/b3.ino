unsigned long t0;
void setup()
{
    // initialize digital pin LED_BUILTIN as an output.

    pinMode(LED_BUILTIN, OUTPUT);

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

    t0 = millis();
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);

    //---- before is just some setups ---------------
    unsigned long t1[10][2];
    unsigned long t2[10][2];
    // t1 is for moter 1
    t1[0][0] = t0; // time
    t1[0][1] = 0;  // velocity
    t1[1][0] = t0 + 1000 * 1;
    t1[1][1] = 50;
    t1[2][0] = t0 + 1000 * 2;
    t1[2][1] = 150;
    t1[3][0] = t0 + 1000 * 3;
    t1[3][1] = 200;
    for (int i = 4; i < 6; i++)
    {
        t1[i][0] = t0 + 1000 * i;
        t1[i][1] = 200;
    }
    for (int i = 6; i < 10; i++)
    {
        t1[i][0] = t0 + 1000 * i;
        t1[i][1] = 0;
    }

    // t2 is for moter 2
    t2[0][0] = t0; // time
    t2[0][1] = 0;  // velocity
    t2[1][0] = t0 + 1000 * 4;
    t2[1][1] = 50;
    t2[2][0] = t0 + 1000 * 5;
    t2[2][1] = 150;
    t2[3][0] = t0 + 1000 * 6;
    t2[3][1] = 200;
    for (int i = 4; i < 10; i++)
    {
        t2[i][0] = t0 + 1000 * i;
        t2[i][1] = 100;
    }
    //-----------------------

    // for moter 1
    int x = 0; // xiabiao
    while (millis() < t1[x][0])
    {
        x++;
    }
    analogWrite(9, t1[x][1]);
    // for moter 2
    x = 0; // xiabiao
    while (millis() < t2[x][0])
    {
        x++;
    }
    analogWrite(10, t2[x][1]);
}
