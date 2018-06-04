/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11;
const int ledPinBlue = 12;
const int ledPinGreen = 13;

// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(ledPin, OUTPUT);
pinMode(ledPinBlue, OUTPUT);
pinMode(ledPinGreen, OUTPUT);

Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);


delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

//Led-ul rosu
if(distance <= 10){
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(ledPin, LOW);
}

//Led-ul albastru
if(distance > 10 && distance <= 20){
  digitalWrite(ledPinBlue, HIGH);
}
else{
  digitalWrite(ledPinBlue, LOW);
}

//Led-ul verde
if(distance > 20){
  digitalWrite(ledPinGreen, HIGH);
}
else{
  digitalWrite(ledPinGreen, LOW);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
