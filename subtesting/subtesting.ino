#include<Adafruit_PWMServoDriver.h>
#include<Wire.h>

// testing input a single pwm value base servo pin 1

// driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// pwm value
int value = 1000;

// Min PWM
int MIN = 0;

// Max PWM
int MAX = 4096;

// Servo Pinconst int SERVO = 2 ELBOW
const int SERVO = 2;

// convert value to pulse width and control Servo
void setPulse(int pin, int value) {
  int pulse_width;

  // convert to pulse width
  pulse_width = int(float(value) / 1000000 * 50 * 4096);
  
  // Display value and pulse width to serial monitor
  Serial.print("PulseWidth: ");
  Serial.println(value);
  Serial.print("Output: ");
  Serial.println(pulse_width);

  // Control servo
  pwm.setPWM(pin, 0, pulse_width);
}

void setup() {
  // Default setup
  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.begin(115200);
  setPulse(SERVO, value);
}

void loop() {
  char ch;

  if(Serial.available()) {
    ch = Serial.read();
    
    // if press 'w' increase value until MAX
    if(ch == 'w') {
      if(value < MAX)
        value += 10;
      setPulse(SERVO, value);
    }

    // if press 's' decrease value until MIN
    if(ch == 's') {
      if(value > MIN)
        value -= 10;
      setPulse(SERVO, value);
    }
  }
}
