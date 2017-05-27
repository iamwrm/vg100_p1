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

int m_t(unsigned int formerT, unsigned int laterT)
{
    if ((millis() > formerT) && (millis() < laterT))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void my_acce(int pin_name, int acce_time, int v_low, int v_high)
{
    unsigned long time_begin;
    time_begin = millis();
    while (millis() < time_begin)
    {
        unsigned long time_past;
        time_past = millis() - time_begin;
        analogWrite(pin_name, v_low + time_past / acce_time * (v_high - v_low));
    }
}

// the loop function runs over and over again forever
void loop()
{
    unsigned long t[10];

    // 0 - 10
    t[0] = t0;
    t[1] = t0 + 1000 * 10;

    // 5 - 15
    t[2] = t0 + 1000 * 5;
    t[3] = t0 + 1000 * 15;

    t[4] = t0 + 4000 * 3;

    int i;

    if (m_t(t[0], t[1]))
    {
        digitalWrite(LED_BUILTIN, HIGH);

        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        my_acce(9, 1000, 0, 200);

        while (millis() < t[0] + 9 * 1000)
        {

            analogWrite(9, 200);
        }

        my_acce(9, 1000, 200, 0);
    }
    if (millis() > t[1])
    {
        // to stop
        analogWrite(9, 0);
    }

    if (m_t(t[2], t[3]))
    {
        digitalWrite(LED_BUILTIN, HIGH);
        i = 200;
        my_acce(10, 1000, 0, 200);
        while (millis() < t[0] + 9 * 1000)
        {
            analogWrite(10, 200);
        }
        my_acce(10, 1000, 200, 0);
    }

    if (millis() > t[3])
    {
        // to stop
        analogWrite(10, 0);
    }
}

