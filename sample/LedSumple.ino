
/*
Blink
Turns on an LED on for one second, then off for one second, repeatedly.

This example code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:


// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
    int i;

    for(i=22;i<=34;i++){
        pinMode(i, OUTPUT);
    }
}

// the loop routine runs over and over again forever:
void loop() {
    int j,k;

    for(j=22;j<=34;j++){
        digitalWrite(j, HIGH); // turn the LED on (HIGH is the voltage level)
    }
    delay(2); // wait for a second

    for(k=22;k<=34;k++){
        digitalWrite(k, LOW); // turn the LED off by making the voltage LOW
    }
    delay(10); // wait for a second

}