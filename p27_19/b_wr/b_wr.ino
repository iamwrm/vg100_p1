unsigned long t0;
void setup()
{
    // initialize digital pin LED_BUILTIN as an output.

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

// the loop function runs over and over again forever
void loop()
{
    unsigned long t[10];
    t[1] = t0 + 1000 * 3;
    t[2] = t0 + 2000 * 3;
    t[3] = t0 + 3000 * 3;
    t[4] = t0 + 4000 * 3;
    int i;
    if (m_t(t[1], t[2]))
    {

        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        analogWrite(9, i);
    }
    if (m_t(t[3], t[4]))
    {
        analogWrite(10, i);
    }
    if (m_t(t[3], t[3] + 1000))
    {
        // digitalWrite(LED_BUILTIN, HIGH); // turn the LED off by making the voltage LOW
    }
}
