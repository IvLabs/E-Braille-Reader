
#define I1 3
#define I2 5
int currentposition = 0;
int targetposition=0, flag;
int encoder, prev, now;
char character = 'a'-1 ;





void setup()
{
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(A0, INPUT);  

}

void go ( int targetposition )
{
  prev = 0;
    if(targetposition > currentposition){
      flag =1;
    }
  else{
      flag =0;
    }


    while( flag == 1 ){
    analogWrite(I1, 80); //95 //120 //100
    digitalWrite(I2, LOW);
    
  encoder = analogRead(A0);
    if(encoder >900){
      now = 1;
    }
    else{
     now = 0;
    }
  
    if(now != prev && now ==0)
    {
      currentposition++;
    }

    if(currentposition == targetposition)
    {
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      break;
    }

    prev = now;

    }

    while( flag == 0 ){
    analogWrite(I2, 40); //95 //120 //50
    digitalWrite(I1, LOW);
  encoder = analogRead(A0);
    if(encoder >900){
      now = 1;
    }
    else{
     now = 0;
    }
  
    if(now != prev && now ==0)
    {
      currentposition--;
    }

    if(currentposition == targetposition)
    {
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      break;
    }

    prev = now;

    }

}

void loop() 
{

 
if ( Serial.available() > 0 )
 {
     character = Serial.read();
     Serial.println(character);     
     delay(1000);
     
 }



targetposition = character - 'a' +1 ;
Serial.println(targetposition);
delay(1000);

//go(targetposition);
 

}
