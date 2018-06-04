const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPinBlue =  10;      // the number of the LED pin
const int ledPinRed = 9;
const int ledPinYellow = 8;
const int echo = 11;
const int trig = 12;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

long duration;
int distance;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input

  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  //PORTB = PORTD;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  
  
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  
  if(distance <= 10){
   digitalWrite(ledPinRed, HIGH);   // set the LED on
   digitalWrite(ledPinYellow, LOW);   // set the LED on
   digitalWrite(ledPinBlue, LOW);   // set the LED on
   
   delay(50);              // wait for a second
   
   digitalWrite(ledPinRed, LOW);    // set the LED off
   digitalWrite(ledPinYellow, HIGH);   // set the LED on
   digitalWrite(ledPinBlue, LOW);   // set the LED on
   
   delay(50);              // wait for a second
   
   digitalWrite(ledPinRed, LOW);    // set the LED off
   digitalWrite(ledPinYellow, LOW);   // set the LED on
   digitalWrite(ledPinBlue, HIGH);   // set the LED on
   
   delay(50);              // wait for a second
  }
  else{
   digitalWrite(ledPinRed, LOW);   // set the LED on
   digitalWrite(ledPinYellow, LOW);   // set the LED on
   digitalWrite(ledPinBlue, LOW);   // set the LED on
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  /*
   digitalWrite(ledPinRed, HIGH);   // set the LED on
   digitalWrite(ledPinYellow, LOW);   // set the LED on
   digitalWrite(ledPinBlue, LOW);   // set the LED on
   
   delay(50);              // wait for a second
   
   digitalWrite(ledPinRed, LOW);    // set the LED off
   digitalWrite(ledPinYellow, HIGH);   // set the LED on
   digitalWrite(ledPinBlue, LOW);   // set the LED on
   
   delay(50);              // wait for a second
   
   digitalWrite(ledPinRed, LOW);    // set the LED off
   digitalWrite(ledPinYellow, LOW);   // set the LED on
   digitalWrite(ledPinBlue, HIGH);   // set the LED on
   
   delay(50);              // wait for a second
*/

    
  //digitalWrite(ledPin, HIGH);
}
/*
// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  */
