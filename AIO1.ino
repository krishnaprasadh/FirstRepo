//Gas Sensor
// Digital pin 8 will be called 'pin8'
int pin8 = 8;
// Analog pin 0 will be called 'sensor'
int sensor = A0;
// Set the initial sensorValue to 0
int sensorValue = 0;

//MotionDetector Alarm Circuit
//Will turn on the buzzer on pin 12 when the sensor detects motion
const int buzzerPin= 12;
//Input pin - represents PIR sensor pin2  
const int inputPin= 2;

//MotionSensor - Automatic Light Circuit
//LED pin-13
const int ledPin= 13;
//PIR Sensor- pin2
const int inputPin= 2;

//Heat Detector Circuit
const int ledPin=13; //the code will flash the LED connected to pin 13
const int sensorPin= 0; //Sensor pin connects to analog pin A0
int level; //the variable that will hold the heat level reading
const int threshold=700; //this represents the threshold voltage. If voltage is below 300, this triggers the LED to turn on

//Sound Detection - Sound Sensor
int soundDetectedPin = 10; // Use Pin 10 as our Input
int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
boolean bAlarm = false;
unsigned long lastSoundDetectTime; // Record the time that we measured a sound
int soundAlarmTime = 500; // Number of milli seconds to keep the sound alarm high







// The setup routine runs once when you press reset
void setup() {
  //Gas Sensor
  // Initialize the digital pin 8 as an output
  pinMode(pin8, OUTPUT);
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);


  //MotionDetector Alarm Circuit
  //buzzer as output 
  pinMode(buzzerPin, OUTPUT);
  //the output of the PIR motion sensor as input
  pinMode(inputPin, INPUT);

  //MotionSensor - Automatic Light Circuit
  //Declaring LED as output
  pinMode(ledPin, OUTPUT);
  //Input pin as input
  pinMode(inputPin, INPUT);

  //Heat Detector Circuit
  pinMode (ledPin, OUTPUT); //sets digital pin 13 as output
  Serial.begin(9600); //sets the baud rate at 9600 so we can check the values the sensor is obtaining on the Serial Monitor

  //Sound Detection - Sound Sensor
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
}











// The loop routine runs over and over again forever
void loop() {
  //Gas Sensor
  // Read the input on analog pin 0 (named 'sensor')
  sensorValue = analogRead(sensor);
  // Print out the value you read
  Serial.println(sensorValue, DEC);
  // If sensorValue is greater than 500
  if (sensorValue > 500) {
    // Activate digital output pin 8 - the LED will light up
    digitalWrite(pin8, HIGH);
  }
  else {
    // Deactivate digital output pin 8 - the LED will not light up
    digitalWrite(pin8, LOW);
  }


  //MotionDetector Alarm Circuit
  //reads the input value and assigns it to the integer named value
  int value= digitalRead(inputPin);
  // If it is HIGH, then the motion sensor has detected motion-turns buzzer ON
  if (value == HIGH)
  {
  digitalWrite(buzzerPin, HIGH);
  }

  //MotionSensor - Automatic Light Circuit
  //Reads and assigns sensor value to int value
  int value= digitalRead(inputPin);
  //if high the LED is turned on
  if (value == HIGH)
  {
  digitalWrite(ledPin, HIGH);
  //Stays on for 60 seconds
  delay(60000);
  digitalWrite(ledPin, LOW);
  }
  else
  {
  digitalWrite(ledPin, LOW);
  }

  //Heat Detector Circuit
  level= analogRead(sensorPin); //the sensor takes readings from analog pin A0
  if (level < threshold){
  digitalWrite(ledPin, HIGH); //if the light level is below the threshold level, the LED turns on
  }
  else{ 
  digitalWrite(ledPin, LOW); //otherwise, if the light level is above the threshold level, the LED is off
  }

  //Sound Detection - Sound Sensor
  soundDetectedVal = digitalRead (soundDetectedPin) ; // read the sound alarm time
  if (soundDetectedVal == LOW) // If we hear a sound
  {
  lastSoundDetectTime = millis(); // record the time of the sound alarm
  // The following is so you don't scroll on the output screen
   if (!bAlarm){
   Serial.println("LOUD, LOUD");
   bAlarm = true;
    }
  }
  else
  {
    if( (millis()-lastSoundDetectTime) > soundAlarmTime  &&  bAlarm){
      Serial.println("quiet");
      bAlarm = false;
    }
  }

}
