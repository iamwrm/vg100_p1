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
        t[0][i][0] = (double)(i)*30*1000 / 150;
        t[0][i][1] = 0;
    }
    for (int i = 0; i < time_frame_max; i++)
    {
        t[1][i][0] = (double)(i)*30*1000 / 150;
        t[1][i][1] = 0;
    }

    //---------------------------------------------
    //  xx      ----- moto 1
    // x x
    //   x
    //   x
    // xxxx
    t[0][0][1] = 0; // velocity
    for (char b = 0 * 5; b < 5 * 5; b++)
    {
        t[0][b][1] = (b - 0 * 5) * 50 / 5;
    }
    for (int b = 5 * 5; b < 10 * 5; b++)
    {
        t[0][b][1] = 240;
    }

    for (char b = 15 * 5; b < 20 * 5; b++)
    {
        t[0][b][1] = (b - 15 * 5) * 50 / 5;
    }

    // xxxxx      ----- moto 2
    //     x
    // xxxxx
    // x
    // xxxxx
    t[1][0][1] = 0; // velocity
    for (char b = 5 * 5; b < 10 * 5; b++)
    {
        t[1][b][1] = (b - 5 * 5) * 50 / 5;
    }
    for (int b = 10 * 5; b < 30 * 5; b++)
    {
        t[1][b][1] = 20;
    }
    for (int b = 0; b < time_frame_max; b++)
    {
        Serial.print("b:");
        Serial.print(b);
        Serial.print("{}");
        Serial.print(t[0][b][0]);
        Serial.print("{}");
        Serial.println(t[1][b][0]);
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
    while (millis() > t0 + (t[0][x][0]))
    {

        x++;
    }
    analogWrite(9, t[0][x][1]);

    // for moter 2
    x = 0; // xiabiao
    while (millis() > t0 + (t[1][x][0]))
    {

        x++;
    }
    analogWrite(10, t[1][x][1]);

    //--------debug
    Serial.print(millis());
    Serial.print("__");
    Serial.print(t[0][x][1]);
    Serial.print("%");
    Serial.println(t[1][x][1]);
    //--------debug

    if (millis() > t0 + 1000 * 30)
    {
    }
}




