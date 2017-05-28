unsigned long t0;

// total max time 30s
// frame 150 -> 1 s 5 frame
#define time_frame_max 150
int t[2][time_frame_max][2];
//  t[switch mot][time_frame][time stamp or velocity]

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
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

    //---- before is just some setups ---------------

    // t[0] is for moter 1
    // 30 s real time
    for (int i = 0; i < time_frame_max; i++)
    {
        t[0][i][0] = (double)(i)*1000 / 30;
        t[0][i][1] = 0;
    }
    for (int i = 0; i < time_frame_max; i++)
    {
        t[1][i][0] = (double)(i)*1000 / 30;
        t[1][i][1] = 0;
    }

    t[0][0][1] = 0; // velocity
    for (char b = 0; b < 5 * 5; b++)
    {
        t[0][b][1] = b * 50 / 5;
    }
    for (int b = 25; b < 30 * 5; b++)
    {
        t[0][b][1] = 20;
    }

    t[1][0][1] = 0; // velocity
    for (char b = 0; b < 5 * 5; b++)
    {
        t[1][b][1] = b * 50 / 5;
    }
    for (int b = 25; b < 30 * 5; b++)
    {
        t[1][b][1] = 20;
    }
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);

    //-----------------------

    // for moter 1
    int x = 0; // xiabiao
    while (millis() > t0 + (unsigned long)(t[0][x][0]))
    {
        if (x < time_frame_max)
            x++;
    }
    analogWrite(9, t[0][x][1]);
    //--------debug
    Serial.println(x);
    //--------debug
    // for moter 2
    x = 0; // xiabiao
    while (millis() > t0 + (unsigned long)(t[1][x][0]))
    {
        if (x < time_frame_max)
            x++;
    }
    analogWrite(10, t[1][x][1]);

    if (millis() > t0 + 1000 * 30)
    {
        delay(1000 * 500);
    }
}

