//Declare the potentioeter and the temperature sensor pins
const int potentiometer= A1;
const int Temperature= 0;

//declare each led pin
const int led1= 9;
const int led2= 8;
const int led3= 7;
const int led4= 6;
const int led5= 5;
const int led6= 4;
const int led7= 3;
const int led8= 2;
const int led9= 1;
const int led10= 0;

//Declare the variables for the temp regulation
int pot_regulator= 0;
int adjust_temp= 0;

//declare leds as outputs
void setup() {
  
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);
pinMode(led10, OUTPUT);

}

//main program

void loop() {
  
//read voltage from the temp sensor and transform to celsius
   int reading = analogRead(Temperature);
    float voltage = reading * 5.0;
 voltage /= 1024.0; 
 float TemperatureC = (voltage - 0.5) * 100 ; 
 
//This part if for regulating the temperature
//in this program we divide the value of the potenciometer by 30 to have 30 degrees of regulation
//if you divide by 100 you have 10 degrees of regulation
// and divided by 50 you get 20 degrees of regulation
//the values are only aproximate they are not exact

   pot_regulator=analogRead(potentiometer);
  adjust_temp=pot_regulator/30;
  delay(50);
  

//the temperature is read and the leds light up for the temperature that is measuring

  if(TemperatureC<(10-adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);

  }
  else if(TemperatureC<(20-adjust_temp) && TemperatureC>(10-adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
  else if(TemperatureC<(30-adjust_temp) && TemperaturaC>(20-adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
  else if(TemperaturaC<(40-adjust_temp) && TemperaturaC>(30-adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
  else if(TemperatureC<(50-adjust_temp) && TemperatureC>(40- adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
  else if(TemperatureC<(60- adjust_temp) && TemperatureC>(50- adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
    else if(TemperatureC<(70- adjust_temp) && TemperatureC>(60- adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
    else if(TemperatureC<(80- adjust_temp) && TemperatureC>(70- adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
  }
    else if(TemperaturaC<(90- adjust_temp) && TemperaturaC>(80- adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      digitalWrite(led9, HIGH);
      digitalWrite(led10, LOW);
  }
  else if(TemperaturaC>(100- adjust_temp)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, HIGH);
      digitalWrite(led9, HIGH);
      digitalWrite(led10, HIGH);
  }
}

