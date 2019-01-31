#include<Adafruit_PWMServoDriver.h>
#include<Wire.h>

// Adafruit PWM Servo instance
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo Out PIN number
// BASE, SHOULDER, ELBOW, ROLL, PITCH, WRIST
const int BASE = 0;
const int SHOULDER = 1;
const int ELBOW = 2;
const int ROLL = 3;
const int PITCH = 4;
const int WRIST = 5;

// Analog Servo frequency 50Hz or 60Hz for analog servo
const int FREQUENCY = 50;

// Default MIN PWM
const int DEFAULT_MIN = 1000;

// Default MAX PWM
const int DEFAULT_MAX = 2500;

// Determine Max PWM for each 6 servos
// Servo1: BASE pin 0

// Servo2: SHOULDER pin 1
// Servo3: ELBOW pin 2
// Servo4: ROLL pin 3
// Servo5: PITCH pin 4
// Servo6: WRIST Pin 5

// Determin Min PWM for each 6 servos

// Setup phase
void setup() {
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  // Open serial monitor for debugging and monitoring
  Serial.begin(115200);

}


// store const default value to variable
int valueMin = DEFAULT_MIN;
int valueMax = DEFAULT_MAX;

// Runtime phase
void loop() {
  // Declare a char variable for storing input '-' & '+'
  char ch;

  // Get keyboard input for increasing and decreasing the PWM value
  if(Serial.available()) {
    ch = Serial.read();
    switch(ch) {
    case 'w':
      // Press '+' increases the PWM value for controlling the servo shaft
      if(valueMin <= DEFAULT_MAX){ // Move only if DEFAULT_MIN is smaller or equals to DEFAULT_MAX
        pwm.setPWM(BASE, 0, valueMin);
        Serial.println(valueMin);
        valueMin += 10;
      }
      break;
    case 's':
      // Press '-' decreases the PWM value for moving the servo shaft
      if(valueMax >= DEFAULT_MIN) {  // move only if DEFAULT_MAX is bigger or equals to DEFAULT_MIN
        pwm.setPWM(BASE, 0, valueMax);
        Serial.println(valueMax);
        valueMax -= 10;
      }
      break;
    }
  }
}

// Can angle be determined from the max and min PWM?
// Can each joint angle can be determined from The robotarm?
