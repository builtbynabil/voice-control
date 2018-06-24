int yellow = 8;
int red = 9;
int buzzer = 10;
String input;
boolean redCommand;

void setup() {
  Serial.begin(9600);
  pinMode(yellow, OUTPUT);
  pinMode(red , OUTPUT);
  pinMode(buzzer , OUTPUT);
  
}

void loop() {

  while(Serial.available() == 0);
  input = Serial.readString();
  
  
  if(input == "turn on all lights" || input == "turn on")
  {
     digitalWrite(yellow , HIGH);
     digitalWrite(red , HIGH);  

     redCommand = true;
  }
  else if(input == "turn off all lights" || input == "turn off")
  {
      digitalWrite(yellow , LOW);
      digitalWrite(red , LOW); 
     redCommand = false;   
  }

  else if(input == "turn on buzzer" || input == "sound")
  {
    tone(buzzer, 500);
         redCommand = false;
  }
  else if(input == "turn off buzzer" || input == "sound off")
  {
    noTone(buzzer);
         redCommand = false;
  }

  else if(input == "turn on yellow" || input == "yellow" || input == "yellow LED" || input == "01" || input == "zero one")
  {
    digitalWrite(yellow, HIGH);
         redCommand = false;
  }

  else if(input == "turn on red" || input == "red" || input == "red LED" || input == "11" || input == "one one")
  {
    digitalWrite(red, HIGH);
         redCommand = true;
  }

  else if(input == "turn off yellow" || input == "off yellow" || input == "off yellow LED" || input == "00" || input == "zero zero")
  {
    digitalWrite(yellow, LOW);
         redCommand = false;
  }
  
  else if(input == "turn off red" || input == "off red" || input == "off red LED" || input == "10" || input == "one zero")
  {
    digitalWrite(red, LOW);
         redCommand = false;
  }
    
  // defualt
  else
  {
      if(redCommand)
      {               
        digitalWrite(yellow , LOW);
        noTone(buzzer); 
        digitalWrite(red , HIGH); 
        delay(100);
        digitalWrite(red , LOW); 
        delay(100); 
        digitalWrite(red , HIGH); 
        delay(100);
        digitalWrite(red , LOW); 
        delay(100); 
        digitalWrite(red , HIGH);           
      }
      else if(!redCommand)
      {
        digitalWrite(yellow , LOW);
        noTone(buzzer); 
        digitalWrite(red , HIGH); 
        delay(100);
        digitalWrite(red , LOW); 
        delay(100);     
        digitalWrite(red , HIGH); 
        delay(100);
        digitalWrite(red , LOW); 
        delay(100);     
      }
  }

}
