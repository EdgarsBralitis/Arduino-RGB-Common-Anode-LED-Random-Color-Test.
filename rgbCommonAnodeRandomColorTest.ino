
/* RGB LED with common Anode connected to permanent 5V pin.
 * All three ground legs are connected through seperate 10K Ohm resistor each 
 * which are then connected to analog pins used as grounds which we have, so to speek, open or close
 * to the various extent by applaying voltage backpressure*/
int delayTime = 1000;
int maxIntensity = 0;//because ground is fully open when there is no voltage backpressure
int minIntensity = 255;//because ground is fully closed when there is maximum voltage backpressure


int groundRed = 9;
int intensityRed;

int groundGreen = 10;
int intensityGreen;

int groundBlue = 11;
int intensityBlue;
 
void setRandomIntensities() {
  intensityRed = random(maxIntensity, minIntensity + 1);
  intensityGreen = random(maxIntensity, minIntensity + 1);
  intensityBlue = random(maxIntensity, minIntensity + 1);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(groundRed, OUTPUT);
  pinMode(groundGreen, OUTPUT);
  pinMode(groundBlue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  setRandomIntensities();
  
  analogWrite(groundRed, intensityRed);
  analogWrite(groundGreen, intensityGreen);
  analogWrite(groundBlue, intensityBlue);
  
  delay(delayTime);

  
  Serial.println("Intensities for colors red, green, blue: " + String(minIntensity - intensityRed) + 
                  " " + String(minIntensity - intensityGreen) + " " + String(minIntensity - intensityBlue));
  
}
