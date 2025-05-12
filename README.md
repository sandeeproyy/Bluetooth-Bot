# Bluetooth-Bot
a race bot controlled by arduino and hc-05 module via bluetooth
This project involves creating a Bluetooth-controlled robotic bot powered by an Arduino Uno, using a 3S LiPo battery, an HC-05 Bluetooth module, an L298N motor driver, and two 12V 200 RPM geared DC motors. The bot can move forward, backward, left, and right with speed control, which is managed by commands sent from a mobile app or other Bluetooth-enabled device. 

**Key Components**:
- **Arduino Uno**: Central control unit, handling commands and sending signals to the motor driver.
- **HC-05 Bluetooth Module**: Enables wireless communication for controlling the bot remotely.
- **L298N Motor Driver**: Controls the two DC motors' speed and direction.
- **3S Battery (11.1V)**: Supplies power to the motor driver and Arduino, ensuring sufficient voltage for the motors.

**Expected Challenges**:
- **Power Management**: Ensuring the 3S battery's voltage is stable enough for consistent motor performance.
- **Signal Delay**: Although minimized in the code, wireless communication may occasionally introduce minor latency.
- **Wiring & Heat Dissipation**: Properly managing wiring to avoid short circuits and ensuring the L298N motor driver remains cool to prevent overheating.

app used:Arduino Bluetooth Controller

How to Set Up the App with This Code:
Download and connect to the HC-05 module via the Arduino Bluetooth Controller app.
Go to Controller Mode and set up each button with the corresponding character:
Forward button → Send "F"
Backward button → Send "B"
Left button → Send "L"
Right button → Send "R"
Increase Speed button → Send "U"
Decrease Speed button → Send "D"
Key Features of This Code:
Direction Control: Moves in forward, backward, left, and right directions.
Speed Control: Increase and decrease speed with U and D commands.
No Input Lag: Code executes instantly as it receives commands from Bluetooth.
