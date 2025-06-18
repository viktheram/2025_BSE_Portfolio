//this combines the code from both the button and the servo. Instead of replaying the song by simply turning on the light, this time, the arduino replays the song using the servo.
//Most of it was copy pasted. The only thing I changed was (1) replacing the activate light code with the rotate servo (2) changing the range of rotation from the servo. 
//I combined the code from button_replay_01.ino and smrazaS51_rotation_full.ino

#include <Wire.h>  // Library for I2C communication (used by the servo driver)
#include <Adafruit_PWMServoDriver.h>  // Library to control the PCA9685 servo driver

// Create an instance of the PWM servo driver using the default I2C address (0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the pulse width range for the servo (in units out of 4096)
#define SERVO_MIN  60  
#define SERVO_MAX  200 

const int buttonPin = 2;   // Pushbutton pin
const int ledPin = 13;

unsigned long pressTimes[10];  // Stores elapsed time between presses
int pressCount = 0;

unsigned long lastPressTime = 0;
int buttonState = 0;
int lastButtonState = 0;

bool replaying = false;

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging

  pinMode(buttonPin, INPUT);

  pwm.begin();             // Initialize the PWM driver
  pwm.setPWMFreq(50);      // Set frequency to 50Hz, standard for servos
  pwm.setPWM(9,0, SERVO_MIN);
  pwm.setPWM(9, 0, SERVO_MAX);  // Move servo on channel 9 to 0 degrees

  delay(10);               // Short delay to allow the driver to stabilize

}

void loop() {
  if (!replaying) {
    buttonState = digitalRead(buttonPin);

    // LED on while button is held
    if (buttonState == HIGH) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }

    // On rising edge (button press)
    if (buttonState == HIGH && lastButtonState == LOW) {
      unsigned long currentTime = millis();

      if (pressCount == 0) {
        // First press just sets start time
        lastPressTime = currentTime;
        Serial.println("First press recorded.");
      } else if (pressCount < 10) {
        pressTimes[pressCount - 1] = currentTime - lastPressTime;
        Serial.print("Gap ");
        Serial.print(pressCount);
        Serial.print(": ");
        Serial.print(pressTimes[pressCount - 1]);
        Serial.println(" ms");
        lastPressTime = currentTime;
      }

      pressCount++;

      if (pressCount > 10) {
        replaying = true;
        Serial.println("Starting replay...");
      }

      delay(50); // Debounce
    }

    lastButtonState = buttonState;
  }

  if (replaying) {
    for (int i = 0; i < 10; i++) {
      pwm.setPWM(9, 0, SERVO_MIN);  // Move servo on channel 9 to 180 degrees
      delay(SERVO_MAX);
      pwm.setPWM(9, 0, SERVO_MAX);  // Move servo on channel 9 to 0 degrees
      delay(SERVO_MIN);
    
      delay(pressTimes[i]); // Wait the recorded time gap
    }

    Serial.println("Replay complete.");
    replaying = false;     // Stop after one replay
    pressCount = 0;        // Reset for a new cycle
    lastPressTime = 0;
  }

}
