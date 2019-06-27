#include <stdio.h>
#include <ultrasonic.cpp>

int main(){
	ultrasonic a = ultrasonic();
	a.freq = 2;
	a.run();
}

