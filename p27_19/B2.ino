void setup()
{
    // put your setup code here, to run once:
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
}

void loop()
{
    // put your main code here, to run repeatedly:
    int i;
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    analogWrite(9, i);
    delay(19);
    analogWrite(10, i);

    delay(19);

    //digitalWrite(9,HIGH);

    // analogWrite(10,0);
}