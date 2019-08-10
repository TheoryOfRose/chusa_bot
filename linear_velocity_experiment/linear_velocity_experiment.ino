#include <math.h>

#define PWM 82

#define L_PWM 9
#define L_FORW 8
#define L_BACK 7
#define R_PWM 3
#define R_FORW 4
#define R_BACK 2

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(R_PWM, OUTPUT);
  pinMode(R_FORW, OUTPUT);
  pinMode(R_BACK, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(L_FORW, OUTPUT);
  pinMode(L_BACK, OUTPUT);

  digitalWrite(R_FORW, 0);
  digitalWrite(R_BACK, 0);
  digitalWrite(L_FORW, 0);
  digitalWrite(L_BACK, 0);
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R_FORW, HIGH);
  digitalWrite(R_BACK, LOW);
  digitalWrite(L_FORW, HIGH);
  digitalWrite(L_BACK, LOW);
  analogWrite(R_PWM, PWM);
  analogWrite(L_PWM, PWM);
}
