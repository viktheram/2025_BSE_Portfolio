//Very first iteration! This is solely to test the wiring of the button and also start storing the gap between different button presses!

const int buttonPin = 2;   // Pushbutton pin
const int ledPin = 13;     // LED pin

unsigned long pressTimes[10];  // Stores elapsed time between presses
int pressCount = 0;

unsigned long lastPressTime = 0;
int buttonState = 0;
int lastButtonState = 0;

bool replaying = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
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

  // Replay phase
  if (replaying) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);  // Flash briefly to mark "press"
      digitalWrite(ledPin, LOW);
      delay(pressTimes[i]); // Wait the recorded time gap
    }

    Serial.println("Replay complete.");
    replaying = false;     // Stop after one replay
    pressCount = 0;        // Reset for a new cycle
    lastPressTime = 0;
  }
}
