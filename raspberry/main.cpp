#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char** argv)
{
    // Intialize the wiringPi Library
    wiringPiSetup();

    // Set the I/O state of the given pins
    pinMode(0, OUTPUT);
    pinMode(1, INPUT);

    // Turn pin 0 on then off
    digitalWrite(0, HIGH);
    digitalWrite(0, LOW);

    // Read input from pin 1
    int status = digitalRead(1);
    printf("Pin Input = %d\n", status);

    // Exit program
    return 0;
}
