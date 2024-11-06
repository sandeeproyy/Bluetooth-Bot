# HC_05_Racebot
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
