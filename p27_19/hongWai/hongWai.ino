
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
    int a = 0;
    a = digitalRead(7);
    Serial.print(a);
}

