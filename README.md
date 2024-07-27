# Vehicle Parking Sensor Simulation

## Description
This project demonstrates a vehicle parking sensor simulation using an Arduino Mega, an ultrasonic distance sensor, and an LCD display. The system simulates a parking sensor that detects the distance between the vehicle and an obstacle using an ultrasonic sensor. The distance is displayed on an LCD screen, and an alarm system is implemented to provide audio and visual warnings when the vehicle is too close to an obstacle.

## Features
->Ultrasonic Distance Measurement: Measures the distance between the sensor and the obstacle using an ultrasonic sensor.
->LCD Display: Shows the measured distance in centimeters on a 16x2 LCD display.
->LCD Display: Shows the measured distance in centimeters on a 16x2 LCD display.
->Warning System: Uses a buzzer and LED indicators to provide warnings based on distance:
->Green LED: Indicates safe distance (more than 80 cm).
->Red LED: Lights up when the vehicle is too close (less than 80 cm).
->Buzzer: Emits sound to alert the driver when the distance is less than 80 cm.

## Components
Arduino Mega 2560<br>
Ultrasonic Distance Sensor (HC-SR04)
16x2 LCD Display (I2C)
Buzzer
LEDs (Red and Green)
Resistors and Breadboard

### Installation
Wiring:
Connect the ultrasonic sensor's trigger and echo pins to the Arduino.
Connect the LCD display to the Arduino via I2C.
Connect the buzzer and LEDs to the specified digital pins on the Arduino.
Code:
Upload the provided Arduino code to your Arduino Mega 2560 using the Arduino IDE or PlatformIO.
Testing:
Place the sensor in a position where it can measure distance to an obstacle.
Observe the LCD display and the warning system as you move the obstacle closer to the sensor.
Usage
This simulation is useful for understanding how parking sensors work and can be a practical tool for designing and testing similar systems in real-world applications.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
