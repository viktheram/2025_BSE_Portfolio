//this shows the full range of rotation for the smraza S51 SERVO. While I may switch servos through the course of the project, this is the one used right now. 

#include <Wire.h>  // Library for I2C communication (used by the servo driver)
#include <Adafruit_PWMServoDriver.h>  // Library to control the PCA9685 servo driver

// Create an instance of the PWM servo driver using the default I2C address (0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the pulse width range for the servo (in units out of 4096)
#define SERVO_MIN  60  
#define SERVO_MAX  580  

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging
  Serial.println("Controlling servo on channel 9");

  pwm.begin();             // Initialize the PWM driver
  pwm.setPWMFreq(50);      // Set frequency to 50Hz, standard for servos

  delay(10);               // Short delay to allow the driver to stabilize
}

void loop() {
  pwm.setPWM(9, 0, SERVO_MIN);  // Move servo on channel 9 to 0 degrees
  delay(1000);                  // Wait 1 second

  pwm.setPWM(9, 0, SERVO_MAX);  // Move servo on channel 9 to 180 degrees
  delay(1000);                  // Wait 1 second
}
