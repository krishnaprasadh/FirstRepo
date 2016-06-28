//Declare the potentioeter and the temperature sensor pins
const int potentiometer= A1;
const int Temperature= 0;

//declare each led pin
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 5     // make this higher to slow down

//Declare the variables for the temp regulation
int pot_regulator= 0;
int adjust_temp= 0;
//declare leds as outputs
void setup() {
pinMode(REDPIN, OUTPUT);
pinMode(GREENPIN, OUTPUT);
pinMode(BLUEPIN, OUTPUT);
}
//main program
void loop() {  
//read voltage from the temp sensor and transform to celsius
int reading = analogRead(Temperature);
float voltage = reading * 5.0;
voltage /= 1024.0; 
float TemperatureC = (voltage - 0.5) * 100 ; 
pot_regulator=analogRead(potentiometer);
adjust_temp=pot_regulator/30;
delay(50);

//the temperature is read and the leds light up for the temperature that is measuring
int r, g, b; //global variable
if(TemperatureC<(20-adjust_temp)){
// fade from blue to violet
for (r = 0; r < 256; r++) { 
analogWrite(REDPIN, r);
delay(FADESPEED);
} 
}
else if(TemperatureC<(40-adjust_temp) && TemperatureC>(20-adjust_temp)){
// fade from violet to red
for (b = 255; b > 0; b--) { 
analogWrite(BLUEPIN, b);
delay(FADESPEED);
} 
}

else if(TemperatureC<(60-adjust_temp) && TemperatureC>(40-adjust_temp)){
// fade from red to yellow
for (g = 0; g < 256; g++) { 
analogWrite(GREENPIN, g);
delay(FADESPEED);}
}

else if(TemperatureC<(80-adjust_temp) && TemperatureC>(60-adjust_temp)){
// fade from yellow to green
for (r = 255; r > 0; r--) { 
analogWrite(REDPIN, r);
delay(FADESPEED);
}
}

else if(TemperatureC<(100-adjust_temp) && TemperatureC>(80- adjust_temp)){
// fade from green to teal
for (b = 0; b < 256; b++) { 
analogWrite(BLUEPIN, b);
delay(FADESPEED);
}
}
  
else if(TemperatureC>(100- adjust_temp)){
// fade from teal to blue
for (g = 255; g > 0; g--) { 
analogWrite(GREENPIN, g);
delay(FADESPEED);
} 
}
}

