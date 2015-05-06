/*
Author: Benjamin Low (benjamin.low@digimagic.com.sg)
Date: May 2015
Description: Arduino code for reading the SICK DT50 laser sensor
with current output (4mA-20mA) instead of voltage output (0-10V).
Stick a 150 ohm resistor across A9 to AGND with a 100uF capacitor.
Analog output from the sensor goes to A9 and AGND is connected to
common ground.
*/

void setup() {
  Serial.begin(9600);
  analogReadResolution(12); //can set up to 16 bit
}

void loop() {
  int val = analogRead(A9);

  //need to do calibration, here is assuming 200 - 5000mm is set
  //with 4mA - 20mA on the sensor and 745 and 3800 is seen at
  //the serial port
  val = map(val, 745, 3800, 200, 5000);
  Serial.println(val);
  delay(50);
}
