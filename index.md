# Marble Music Machine
Last updated: Jun 27 14:15:41

For full documentation visit [this](https://docs.google.com/document/d/19l-sdvGk2wv6FiNkObK4XHLtHroH8l88qlTdeSVrPsI/edit?tab=t.0#heading=h.u3em2oo7d9ti) google document. Because the github can be hard to navigate, this also includes direct links to everything I used - all my libraries, and direct links to each stage in my prototyping. But, if you don't want to do that, I've created one final release that will allow you to simply download everything you need for final assembly.

This is a music machine that replays the notes you input by dropping marbles onto a Xylophone! Rather than playing directly on the xylophone, you pre-program notes by pushing buttons. After you are done, you press the stop button twice (once to stop and once to start playing) then watch as balls are sent bouncing off the keys of the xylophone. This will loop forever because of the ball lift on the side!
 
### Contents:
<b>Starter Project:</b> The project I did before I started my intensive project<br>
<b>Milestone 1:</b> Program button interface to record and store notes.<br>
<b>Milestone 2:</b> Design method for dropping balls onto the xylophone. Design method to control where the balls drop to (to drop on different notes).<br>
<b>Milestone 3:</b> Design conveyor belt to move marbles back to the top for endless replaying!<br>
<b>Bill of Materials:</b> All the materials I used<br>
<b>Schematics:</b> An schematic of how I wired my wires<br>
<b>Code:</b> My final code and a bit of my setup code.<br>

| **Name** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Vikram D | Hillbrook School | Civil and Mechanical Engineering | Incoming Sophomore |

**Replace the BlueStamp logo below with an image of yourself and your completed project. Follow the guide [here](https://tomcam.github.io/least-github-pages/adding-images-github-pages-site.html) if you need help.**

![Headstone Image](logo.svg)

# Starter Project – Retro Arcade Console
<details>
  <summary>&#9656; Starter Project – Retro Arcade Console</summary>
  <iframe width="875" height="400" src="https://www.youtube.com/embed/-vWqwQfv9GA?si=EgtACB9ZjJk6BhVi" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

  This console has multiple games on like Snake and Tetris. The parts and code were preloaded and all I needed to do was solder different pieces to the main PCB. It can be powered thorugh a mini-USB port or 3AAA batteries.

  <div style="text-align:left"><img src="starter_1_2.png" alt="front of the starter project" width="1500"/> </div>

  This gave me a great way to practice my soldering skills as there were many points I had to solder together. The most challenging part of soldering each contraption while keeping them in place and alligned. The pins were also extremely close together, and I had never had to solder with this much precision before. Attaching the battery was also difficult as I decided to shorten the wire. This meant that I needed to cut the while and re-solder it together. Because I had already attached the wires to the PCB and the battery, soldering them back together was very difficult as I had to position them between the battery and the PCB. I had very little room. However, it turned out great and all the components work!

</details>


# First Milestone

<iframe width="875" height="400" src="https://www.youtube.com/embed/KsqplpovlIQ?si=DtapKUqWkmuTwKQ9" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

I planned to build my project in two stages: The coding stage and the design and building stage. During the coding stage, I worked on programming the arduino to receive inputs from a button, and then replay it on a servo. I started with one buttton and one servo. The code was quite simple as I just needed to record one variable: the gap between the button presses. I used an array to store the values. The hardest part of this stage was setting up the servo shield. Because it didn't use the digital or analog pins on the arduino (but instead used channels), I needed to import libraries and set that up. It wasn't hard once I knew what to do, but the troubleshooting was quite annoying. 

Below: My very simple setup with just one servo and one button. I eventually merged the two together.
<div style="text-align:left"><img src="one_button_servo.png" alt="front of the starter project" width="1500"/> </div>

However, as I got more buzzers, I had to calculate and store more gaps. I needed more arrays, more wires, and more control over the servos. At the beginning, I just duplicated my code to be able to account for more buttons, and then control the respective servos. The servo shield was very helpful at this point. I thought I was done and was quite satisfied.

However, eventually, I found some limitations. These limitations were because my code was recording each button press in relation to the button press before it and storing the time difference. When played on the servo, each servo would also move in relation to the servo before it. However, the delay timer would start only after the servo before stopped moving. As such, each gap would be the programmed gap from the button <i>and</i> the time it took for the servo to rotate. This meant that the song would be played much slower than programmed. It also meant that I wouldn't be able to play any chords.

My updated solution used something different. Instead of storing each servo press in relation to the servo before it, It would store the servo press in relation to the beginning and create a timeline. Then, when replaying the values on the servo, the arduino would go through the timeline, and whenever it reached a stored event (each button press) it would move the servo. I also changed a function. I changed it from <i>delay</i> to <i>millis</i>. That way the timer would be able to run in parallel to everything else. That way, if there were many stored events at the same time, or extremely close together, the arduino would be able to move all servos at the same time using a macro that I defined. And it worked! The start of the rotation of each servo has the exact same gap as the start of each button press.

Now that this was all done, I started printing a case for my arduino and breadboard, and also added a screen. Below you can see my before and after from before the case to after the case. I still have to add a case for my buttons.
<div style="text-align:left"><img src="before_after_cables.png" alt="front of the starter project" width="1500"/> </div>

My next steps are to finish enclosing my buttons and to start working on the dispenser mechanism. I did some prototyping while I was waiting for my buttons to arrive, and in between code updates, but now I need to make it more refined. My current prototype is just made out of cardboard. I will move to using acrylic and making 15 channels. I also need to connect my servo to my turning mechanism.

# Second Milestone
Coming soon!
<!-- **Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/y3VAmNlER5Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your second milestone, explain what you've worked on since your previous milestone. You can highlight:
- Technical details of what you've accomplished and how they contribute to the final goal
- What has been surprising about the project so far
- Previous challenges you faced that you overcame
- What needs to be completed before your final milestone -->

# Final Milestone
Coming soon!
<!-- **Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/F7M7imOVGug" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE -->

# Bill of Materials

**Milestone 1**

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Arduino Mega 2560 | The brains of the entire operation. | $22 | <a href="https://www.amazon.com/ELEGOO-ATmega2560-ATMEGA16U2-Arduino-Compliant/dp/B01H4ZLZLQ?sr=8-3"> Link </a> |
| Keyestudio 16x12 Servo Shield | To attach servos | $15 | <a href="https://www.amazon.com/KEYESTUDIO-16-Channel-12-bit-Shield-Arduino/dp/B0D3L85YQL?sr=8-1"> Link </a> |
| SANWA 30mm Arcade Buttons (8 Pack White)| These are the buttons I used to program the servos. | $24 (x2) | <a href="https://www.amazon.com/White-Sanwa-Push-Buttons-OBSF-30-W/dp/B003KSB2YC"> Link </a> |
| SANWA 30mm ARcade Buttons (2 Pack Black)| I used 17 buttons. 15 white ones are the keys, these two black ones are the start/stop button and the continuous playback button. | $12 | <a href="https://www.amazon.com/OBSF-30-Arcade-Tournament-Joystick-Compatible/dp/B005BZ10EY"> Link </a> |
| Micro Servos (20 Pack) | These are the servos that I controlled. | $31 | <a href="https://www.amazon.com/Smraza-Helicopter-Airplane-Control-Arduino/dp/B0F32WF12W?sr=8-10"> Link </a> |
| IC2 16x12 LCD Display | The display that displayed what the arduino was doing | $9 | <a href="https://www.amazon.com/GeeekPi-Character-Backlight-Raspberry-Electrical/dp/B07S7PJYM6?sr=8-7"> Link </a> |
| 5V Power Adapter 2 Pack | This is what gave power to the arduino and the shield | $10 | <a href="https://www.amazon.com/Power-Adapter-100-240V-Transformers-Supply/dp/B08722QC75?sr=8-3"> Link </a> |
|**Generic Parts:**| Jumper wires, tools for construction (e.g but not limited to 3D printer, filament, wire cutter, jumper wires (MM and MF))| | |


**Milestone 2**

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Acrylic 1mm 11x17 Acrylic (4 Pack)| This is the acrylic I used to create the walls for the marble chute. (After the dispenser mechanism)| $17 | <a href="https://www.amazon.com/ELEGOO-ATmega2560-ATMEGA16U2-Arduino-Compliant/dp/B01H4ZLZLQ?sr=8-3"> Link </a> |
| Acrylic 3mm 12x24 Acrylic (2 Pack) | This is the acrylic I used as the baseplate for my marble storage section. (Before the dispenser mechanism)| $24 | <a href="https://www.amazon.com/2-Pack-Clear-Acrylic-Sheet-Plexiglass/dp/B0899QVSY1?sr=8-3"> Link </a> |
| Balsa Rods | These are the balsa poles I used throughout my project to hold up things (like my button holder) | $15 | <a href="https://www.amazon.com/Calvana-12-Unfinished-Straight-Hardwood/dp/B09TKT51D7?sr=8-2"> Link </a> |
| Balsa Sheets | 12x12x1/8 These are the sheets I used to make dividers and hold my buttons | $15 | <a href="https://www.amazon.com/DIYDEC-Basswood-Plywood-Unfinished-Architectural/dp/B0CYPL3729?sr=8-2"> Link </a> |
| Timing Belt Pulley | This is the wheel that connects to the belt that will lift the marbles back up | $6 | <a href="https://www.amazon.com/WINSINN-Aluminum-Synchronous-Timing-Printer/dp/B07CXSSGF8/ref%5B%25E2%2580%25A6%5D=b61ec422-dde5-4ccc-a123-a7d85c621f51&pd_rd_i=B077GNZK3J&th=1"> Link </a> |
| Timing Belt | This is the belt that attaches to the wheel above. | $13 | <a href="https://www.amazon.com/WINSINN-Aluminum-Synchronous-Timing-Printer/dp/B07CXSSGF8/ref%5B%25E2%2580%25A6%5D=b61ec422-dde5-4ccc-a123-a7d85c621f51&pd_rd_i=B077GNZK3J&th=1"> Link </a> |
| Sandpaper Loop | This is the loop that the timing belt will attach to (for more width and stability) | $$ | Link |
| Flange Coupling Connector | This will connect the servo to a dowel (we will 3D print) that will span the width of the sandpaper | $8 | <a href="https://www.amazon.com/Coupling-Connector-Coupler-Accessory-Fittings/dp/B08334MFVT/r%5B%25E2%2580%25A6%5D020fce7c-0cb7-4eb5-a21e-ebdf8143c417&pd_rd_i=B08334MFVT&psc=1"> Link </a> |

# Schematics 
<div style="position: relative; width: 100%; padding-top: calc(max(56.25%, 400px));">
  <iframe src="https://app.cirkitdesigner.com/project/b5c1739f-cfc4-4bea-ba0a-5540df392f83?view=interactive_preview" style="position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: none;"></iframe>
</div> 

# Code
<p>
  I have many editions of my code which you can find on my 
  <a href="https://github.com/viktheram/2025_BSE_Portfolio/tree/code" target="_blank">github</a>. 
  You may have to download libraries from the github. Below are the most important snippets of code which can help you setup the machine.
</p>

<details>
  <summary><strong>&#9656; I2C_setup</strong></summary>
  <p>Setup code to find the baud rate of the display.</p>

  <pre><code class="language-c++">
#include &lt;LiquidCrystal_I2C.h&gt;
// I2C address finding
#include &lt;Wire.h&gt;

void setup()
{
    //Initializing wire
    Wire.begin();
    //Initializing seraial monitor at the baudrate of 9600
    Serial.begin(9600);
}

void loop()
{
    byte err, addr;
    //Declaring variable to detect and count no. of I2C device found
    int devices = 0;
    
    // For loop to try multiple combinations of Address
    for (addr = 1; addr &lt; 127; addr++) 
    {
        Wire.beginTransmission(addr);
        err = Wire.endTransmission();

        if (!err) 
        {
            Serial.print("Address 0x");
            if (addr &lt; 16)
            {
              Serial.print("0");
            }
            Serial.println(addr, HEX);
            devices++;
        }
        else if (err == 4) 
        {
            Serial.print("Error at address 0x");
            if (addr &lt; 16)
            {
              Serial.print("0");
            }
            Serial.println(addr, HEX);
        }
    }
    
    //Exception, when there is no I2C device found
    if (!devices)
    {
      Serial.println("Please connect your I2C device");
    }
    
    //Waiting for 2 seconds
    delay(2000);
}
  </code></pre>
</details>

<details>
   <summary><strong>&#9656; servo_dispense_setup</strong></summary>
  <p>This is the code for you to figure out the degrees that work the best for dispensing and accepting marbles.</p>

  <pre><code class="language-c++">
#include &lt;Wire.h&gt;
#include &lt;Adafruit_PWMServoDriver.h&gt;

#define PWM_MIN 100
#define PWM_MAX 500
#define SERVO_CENTER_DEG 90
#define SERVO_LEFT_DEG   75
#define SERVO_RIGHT_DEG  100
#define SERVO_CHANNEL    1    // Test
#define SERVO_DELAY      3000 // ms to wait at each position

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int degreesToPWM(int deg) {
  return map(deg, 0, 180, PWM_MIN, PWM_MAX);
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50); // Standard servo frequency
  delay(10);
}

void loop() {
  // Move to left (80°)
  pwm.setPWM(SERVO_CHANNEL, 0, degreesToPWM(SERVO_LEFT_DEG));
  Serial.println("Left");
  delay(SERVO_DELAY);

  // Move to right (100°)
  pwm.setPWM(SERVO_CHANNEL, 0, degreesToPWM(SERVO_RIGHT_DEG));
  Serial.println("Right");
  delay(SERVO_DELAY);
}
  </code></pre>
</details>

<details>
   <summary><strong>&#9656; all_attached_04</strong></summary>
  <p>
    This is the 4th and final edition of my code. Put this into the Arduino, and assuming you have all the libraries installed and all the setup code finished, you should be good to go! At the top, I've linked all the files you'll need for the final project. Remember to save the code in the Arduino folder.
  </p>

<pre><code class="language-c++">
//Might need some tweaks to some numbers
//IMPORTANT SETUP COMMENT AT LINE 86
//IMPORTANT ADJUSTMENT COMMENTA AT LINE 14&15

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// === CONFIGURATION MACROS ===
#define MAX_EVENTS 50
#define PWM_MIN 100
#define PWM_MAX 500
#define SERVO_CENTER_DEG 90
#define SERVO_LEFT_DEG 75 //You may have to adjust SERVO_LEFT to a lower number if marbles are not dispensing properly (default: 75)
#define SERVO_RIGHT_DEG 100 //You may have to adjust SERVO_RIGHT to a higher number if marbles are not entering the dispenser properly (default: 100)
#define SERVO_MOVE_DURATION 75 
bool recording = false;
bool replaying = false;
bool idle = false;

// === HARDWARE SETUP ===
const int buttonPins[17] = {
  22, 24, 26, 28, 30, 32, 34, 36,
  38, 40, 42, 44, 46, 48, 50, 52, 53
};
LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Width,Height )

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// === EVENT & SERVO STATE ===
struct PressEvent {
  byte buttonIndex;
  unsigned long timestamp;  // ms since recording started
  bool triggered;
};

PressEvent events[MAX_EVENTS];
int eventCount = 0;

struct ActiveServo {
  int channel;
  unsigned long phaseStart;
  int phase; // 0=start, 1=return, 2=done
  bool active;
};

#define MAX_ACTIVE_SERVOS 10
ActiveServo activeServos[MAX_ACTIVE_SERVOS];

// === SYSTEM STATE ===
enum SystemState { IDLE, ARMED, RECORDING, REPLAYING };
SystemState currentState = IDLE;

bool buttonStates[17] = {0};
bool lastButtonStates[17] = {0};

bool loopingEnabled = false;
unsigned long recordStartTime = 0;
unsigned long replayStartTime = 0;

void updateActiveServos();
void readButtons();
bool buttonPressed(int index);
void startRecording(int firstButton);
void recordEvent(int buttonIndex);
void startReplay();
void replayEventsNonBlocking();

int degreesToPWM(int deg) {
  return map(deg, 0, 180, PWM_MIN, PWM_MAX);
}

// === SETUP ===
void setup() {

  updateActiveServos();
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);

  for (int i = 0; i < 17; i++) {
    pinMode(buttonPins[i], INPUT);
  }

  for (int ch = 1; ch <= 15; ch++) {
    pwm.setPWM(ch, 0, degreesToPWM(SERVO_RIGHT_DEG)); // Set all servos to right at startup
  }
//WHEN YOU FIRST START UP THE PROGRAM AND YOUR SERVOS
//SET (SERVO_RIGHT_DEG) to (SERVO_CENTER_DEGREE)
//THAT WAY YOU CAN ENSURE YOUR DISPENSERS ARE CENTERED
//Once your dispensers are centerd, change it back to SERVO_RIGHT_DEG

  // initialize the lcd
  lcd.init();
  // Turn on the Backlight
  lcd.backlight();
  //Clear LED
  lcd.clear();

  currentState = IDLE;
}

// === MAIN LOOP ===
void loop() {
  readButtons();

  // Toggle looping
  if (buttonPressed(16)) { 
    loopingEnabled = !loopingEnabled;
    Serial.print("Looping playback is now ");
    Serial.println(loopingEnabled ? "ENABLED" : "DISABLED");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Infinite Loop:");
    lcd.setCursor(1,0);
    lcd.print(loopingEnabled ? "ENABLED" : "DISABLED");
    delay(200);
  }

  switch (currentState) {
    case IDLE:
      for (int ch = 1; ch <= 15; ch++) {
      pwm.setPWM(ch, 0, degreesToPWM(SERVO_AT_START)); //See comment on variable
    }
      
      replaying = false;
      if (idle == false){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Welcome!");
        lcd.setCursor(0,1);
        lcd.print("Press S to start");
        idle = true;
      }
      if (buttonPressed(0)) {
        Serial.println("Started. Press any button 1-15 to begin.");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Started");
        lcd.setCursor(0,1);
        lcd.print("Ready to record");
        idle = false;
        currentState = ARMED;
      }
      break;

    case ARMED:
      for (int i = 1; i <= 15; i++) {
        if (buttonPressed(i)) {
          startRecording(i);
          break;
        }
      }
      break;

    case RECORDING:
      if (recording == false){
        recording = true;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Now recording");
        lcd.setCursor(0,1);
        lcd.print("Press S to stop");
      }
        
      for (int i = 1; i <= 15; i++) {
        if (buttonPressed(i)) {
          recordEvent(i);
        }
      }

      if (eventCount == MAX_EVENTS) {
        Serial.println("Max notes reached. Starting replay.");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Note limit reached");
        lcd.setCursor(0,1);
        lcd.print("Starting replay");
        startReplay();
      }

      if (buttonPressed(0)) {
        delay(100);
        Serial.println("Recording stopped. Starting replay.");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Recording ended");
        lcd.setCursor(0,1);
        lcd.print("Starting replay");
        startReplay();
      }
      break;

    case REPLAYING:
      recording = false;
      if (replaying == false){
        replaying = true;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Now replaying");
        lcd.setCursor(0,1);
        lcd.print("Press S to stop");
      }
      
      replayEventsNonBlocking();
      if (buttonPressed(0)) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Stopped Replay");
        lcd.setCursor(0,1);
        lcd.print("System idle");
        delay(3000);
        currentState = IDLE;
        break;
    } 
  
    updateActiveServos();
    }
  }
  



// === BUTTON HANDLING ===
void readButtons() {
  for (int i = 0; i < 17; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);
  }
}

bool buttonPressed(int index) {
  bool pressed = (buttonStates[index] == HIGH && lastButtonStates[index] == LOW);
  lastButtonStates[index] = buttonStates[index];
  return pressed;
}

// === RECORDING ===
void startRecording(int firstButton) {
  Serial.println("==> Recording started");
  eventCount = 0;
  recordStartTime = millis();
  recordEvent(firstButton);
  currentState = RECORDING;
}

void recordEvent(int buttonIndex) {
  if (eventCount >= MAX_EVENTS) return;

  unsigned long now = millis();
  events[eventCount].buttonIndex = buttonIndex;
  events[eventCount].timestamp = now - recordStartTime;
  events[eventCount].triggered = false;

  Serial.print("Recorded button B");
  Serial.print(buttonIndex);
  Serial.print(" at ");
  Serial.print(events[eventCount].timestamp);
  Serial.println(" ms");

  eventCount++;
}

// === REPLAYING ===
void startReplay() {
  Serial.print("==> Replaying ");
  Serial.print(eventCount);
  Serial.println(" events...");
  replayStartTime = millis();

  for (int i = 0; i < eventCount; i++) {
    events[i].triggered = false;
  }

  currentState = REPLAYING;
}

void replayEventsNonBlocking() {
  unsigned long now = millis() - replayStartTime;
  bool allTriggered = true;

  for (int i = 0; i < eventCount; i++) {
    
    if (!events[i].triggered && now >= events[i].timestamp) {
      int ch = events[i].buttonIndex;
      Serial.print("Turning servo ");
      Serial.println(ch);
      activateServo(ch);
      events[i].triggered = true;
    }

    if (!events[i].triggered) {
      allTriggered = false;
    }
  }

  if (allTriggered) {
    Serial.println("==> Replay complete.");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Replay complete");
      lcd.setCursor(0,1);
      lcd.print("System idle");
      delay(1000);
    if (loopingEnabled) {
      Serial.println("-- Looping replay...");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Loop is on");
      lcd.setCursor(0,1);
      lcd.print("Starting over");
      delay(1000);
      replayStartTime = millis();
      for (int i = 0; i < eventCount; i++) {
        events[i].triggered = false;
      }
    } else {
      currentState = IDLE;
      Serial.println("Returning to IDLE state.");
      Serial.println("Press start to begin recording.");
    }
  }
}

// === SERVO HANDLING (NON-BLOCKING) ===
void activateServo(int ch) {
  for (int i = 0; i < MAX_ACTIVE_SERVOS; i++) {
    if (!activeServos[i].active) {
      activeServos[i] = { ch, millis(), 0, true };
      pwm.setPWM(ch, 0, degreesToPWM(SERVO_LEFT_DEG)); // Move to left
      delay(SERVO_MOVE_DURATION);
      pwm.setPWM(ch, 0, degreesToPWM(SERVO_RIGHT_DEG)); // Move to right
      delay(SERVO_MOVE_DURATION);
      return;
    }
  }
}

void updateActiveServos() {
  unsigned long now = millis();
  for (int i = 0; i < MAX_ACTIVE_SERVOS; i++) {
    if (!activeServos[i].active) continue;

    int ch = activeServos[i].channel;

    if (activeServos[i].phase == 0 && now - activeServos[i].phaseStart >= SERVO_MOVE_DURATION) {
      pwm.setPWM(ch, 0, degreesToPWM(SERVO_LEFT_DEG)); // Return
      activeServos[i].phase = 1;
      activeServos[i].phaseStart = now;
    }
    else if (activeServos[i].phase == 1 && now - activeServos[i].phaseStart >= SERVO_MOVE_DURATION) {
      pwm.setPWM(ch, 0, degreesToPWM(SERVO_RIGHT_DEG)); // Turn off (move to left)
      activeServos[i].active = false;
      activeServos[i].phase = 2;
    }
  }
}
</code></pre>
</details>

<details>
 <summary>&#9656; Helpful Resources</summary>
 Other Resources/Examples
 
 <p>One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.
</p>
</details>
