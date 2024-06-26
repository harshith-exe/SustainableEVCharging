#include <Servo.h>

Servo mg90;
int initial_position = 90;
int LDR1 = A0;
int LDR2 = A1;
int error = 20;
int servopin = 2;

void setup() {
  mg90.attach(servopin);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  mg90.write(initial_position);
  delay(2000);
}

void loop() {
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);
  int diff1 = abs(R1 - R2);
  int diff2 = abs(R2 - R1);
  
  if (diff1 <= error || diff2 <= error) {
    // Do nothing if difference is within error range
  } else {
    if (R1 > R2) {
      initial_position = -initial_position;
    }
    if (R1 < R2) {
      initial_position = initial_position + 1;
    }
    mg90.write(initial_position);
    delay(100);
  }
}
