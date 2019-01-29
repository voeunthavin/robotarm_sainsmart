#include<Wire.h>
#include<Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define OFFSET 1500
#define FREQUENCY 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int servo1 = 0;
int servo2 = 1;
int servo3 = 2;
int servo4 = 3;
int servo5 = 4;
int servo6 = 5;

char c;
int a;

void setup() {
    pwm.begin();
    Serial.begin(115200);
    pwm.setPWMFreq(FREQUENCY);
}

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
