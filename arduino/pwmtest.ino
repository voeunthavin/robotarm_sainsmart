#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define OFFSET 1500
#define FREQUENCY 50

// Instantiate the Adafruit driver class
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// BASE, SHOULDER, ELBOW, ROLL, PITCH, WRIST
int BASE = 0;
int SHOULDER = 1;
int ELBOW = 2;
int ROLL = 3;
int PITCH = 4;
int WRIST = 5;

// Variable for manipulation
char c;
int a;

// Method for pulse width conversion and controll servo
void setPulse(int pin, int value) { // Take 2 params: pin num & value
  // Convert to pulse width
  int pulse_width;
  pulse_width = int(float(value) / 1000000 * FREQUENCY * 4096);
 
  // Control the servo
  pwm.setPWM(pin, 0, pulse_width);
}

void setup() {
    pwm.begin();
    Serial.begin(115200);
    pwm.setPWMFreq(FREQUENCY);
}

// Method for angle munipulation on the Servo
void setAngle(int angle, int servoOut) {
    int pulse_wide, pulse_width;

    // convert to pulse width
    pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);

    // Control Servo
    pwm.setPWM(servoOut, 0, pulse_width);
}

void loop() {
    // Controll Servo1
    while(Serial.available()) {
        c = Serial.read();

        switch(c) {
        case 'b':
            setAngle(a, servo1);
            a = 0;
            break;
        case 'e':
            setAngle(a, servo2);
            a = 0;
            break;
        case 's':
            setAngle(a, servo3);
            a = 0;
            break;
        case 'r':
            setAngle(a, servo4);
            a = 0;
            break;
        case 'p':
            setAngle(a, servo5);
            a = 0;
            break;
        case 'w':
            setAngle(a, servo6);
            a = 0;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            a = 10 * a + (c - '0');
            break;
        }
    }
}
