#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX pins for HC-05

// Motor control pins
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define EN1 9
#define EN2 10

int speedValue = 255; // Initial motor speed (0-255)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  BTSerial.begin(9600); // Start Bluetooth communication
  Serial.begin(9600);   // For debugging
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    Serial.println(command); // For debugging

    switch (command) {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case 'U':
        increaseSpeed();
        break;
      case 'D':
        decreaseSpeed();
        break;
      default:
        stopMotors();
        break;
    }
  }
}

void moveForward() {
  analogWrite(EN1, speedValue);
  analogWrite(EN2, speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(EN1, speedValue);
  analogWrite(EN2, speedValue);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(EN1, speedValue);
  analogWrite(EN2, speedValue);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(EN1, speedValue);
  analogWrite(EN2, speedValue);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void increaseSpeed() {
  speedValue = min(255, speedValue + 10); // Cap at 255
  Serial.print("Speed increased to: ");
  Serial.println(speedValue);
}

void decreaseSpeed() {
  speedValue = max(0, speedValue - 10); // Bottom at 0
  Serial.print("Speed decreased to: ");
  Serial.println(speedValue);
}
