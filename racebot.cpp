// Motor Control Pins
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define EN1 9  // Motor 1 speed control (PWM)
#define EN2 10 // Motor 2 speed control (PWM)

// Bluetooth Input Variables
char command;

void setup() {
  // Motor Control Pins as Outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  
  // Initialize Serial for Bluetooth Communication
  Serial.begin(9600);
}

void loop() {
  // Check if data is available on Serial (Bluetooth)
  if (Serial.available() > 0) {
    command = Serial.read(); // Read the incoming command

    switch (command) {
      case 'F': // Forward
        moveForward(255);
        break;
      case 'B': // Backward
        moveBackward(255);
        break;
      case 'L': // Left
        turnLeft(255);
        break;
      case 'R': // Right
        turnRight(255);
        break;
      case 'S': // Stop
        stopMotors();
        break;
    }
  }
}

// Motor Control Functions

void moveForward(int speed) {
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward(int speed) {
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft(int speed) {
  analogWrite(EN1, speed / 2); // Reduce speed for turning
  analogWrite(EN2, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight(int speed) {
  analogWrite(EN1, speed);
  analogWrite(EN2, speed / 2); // Reduce speed for turning
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
