#define encoderPin 2
#define E1 10
#define M1 7
#define M2 8

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int input;
int previous;


void setup() {
  Serial.begin(9600);
  pinMode(encoderPin, INPUT);   
  pinMode(M1,OUTPUT);;
  pinMode(M2,OUTPUT);
  pinMode(E1,OUTPUT);  
}


void loop()
{ Serial.flush();
  Serial.print(" TYPE INTEGET BELOW 8 ");
  if(Serial.available()>0)
    {
    input=Serial.read();
    if(input>previous)
    {
      GoAnti((input-previous));
    }
    else if(input<previous)
    {
      GoClockwise((previous-input));
    }
    }
  


}


void GoAnti(int steps)
{   int buttonPushCounter = 0;   // counter for the number of button presses
    int buttonState = 0;         // current state of the button
    int lastButtonState = 0;     // previous state of the buttonbuttonPushCounter=0;
    
    
    while(buttonPushCounter < steps)
   {

   analogWrite(E1,100);
   digitalWrite(M1,HIGH);
   digitalWrite(M2,LOW);
   buttonState = digitalRead(encoderPin);

   if (buttonState != lastButtonState)
   {    
   if (buttonState == LOW) 
   {     
   buttonPushCounter++;
   Serial.print("number of button pushes:  ");
   Serial.println(buttonPushCounter);
   }    
    delay(5);
  }

  lastButtonState = buttonState;  
   }
  
}






