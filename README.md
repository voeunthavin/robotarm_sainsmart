# Arduino Testing

Using [android-mk][1] to let the LED blink.

```Shell
usermod $USER -a -G dialout
sudo install arduino-mk
make 
make upload
```

Use *screen* to connect to the Arduino board and control the LED

```Shell
screen /dev/ttyACM0 115200
```
TODO

Make Servo Running smoother
Set correct Min and Max pulse width for each servo as array
Store teachpoint for the robotarm
