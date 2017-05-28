unsigned long t0;

// total max time 30s 
// frame 150 -> 1 s 5 frame 
#define time_frame_max 150
int t[2][time_frame_max][2];

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
    t[0][0][0] = 0; // time
    t[0][0][1] = 0; // velocity
    t[0][1][0] = 1000 * 1;
    t[0][1][1] = 50;
    t[0][2][0] = 1000 * 2;
    t[0][2][1] = 150;
    t[0][3][0] = 1000 * 3;
    t[0][3][1] = 200;
    for (int i = 4; i < 6; i++)
    {
        t[0][i][0] = 1000 * i;
        t[0][i][1] = 200;
    }
    for (int i = 6; i < time_frame_max; i++)
    {
        t[0][i][0] = 1000 * i;
        t[0][i][1] = 0;
    }

    // t[1] is for moter 2
    t[1][0][0] = 0; // time
    t[1][0][1] = 0; // velocity
    t[1][1][0] = 1000 * 4;
    t[1][1][1] = 50;
    t[1][2][0] = 1000 * 5;
    t[1][2][1] = 150;
    t[1][3][0] = 1000 * 6;
    t[1][3][1] = 200;
    for (int i = 4; i < time_frame_max; i++)
    {
        t[1][i][0] = 1000 * i;
        t[1][i][1] = 100;
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
        x++;

        Serial.println("x");
        Serial.println(x);
    }
    analogWrite(9, t[0][x][1]);
    Serial.println(t[0][x][1]);
    // for moter 2
    x = 0; // xiabiao
    while (millis() > t0 + (unsigned long)(t[1][x][0]))
    {
        x++;
    }
    analogWrite(10, t[1][x][1]);
}









