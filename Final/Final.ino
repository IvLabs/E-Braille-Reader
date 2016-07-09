
//Encoder3 on A3
//Encoder2 on A2
//Encoder1 on A1

//D = Digital Pin
//Moter1 on D3 D5    01 -> Unwind 10
//Moter2 on D7 D6    10 -> Wind up 
//Moter1 on D8 D9    For All


#define M31 3
#define M32 5
#define M21 7
#define M22 6
#define M11 8
#define M12 9
    
int m1,m2, m3;     //Target Position for Motor 1
int current1=1,   current2=1,    current3=1; // Current position for motor 1; this variable is the memory element for motor1


void setup(){

  
  Serial.begin(9600);  
  Serial.println("<Arduino is ready>");
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  pinMode(M31, OUTPUT);
  pinMode(M32, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);

 // target is set to 3=c
  

}

void loop() {
  
  Serial.println("Void_Loop_Restart");

  m1=2; // target is set to 3=c
  m2=2; // target is set to 3=c
  m3=2; // target is set to 3=c
  
  
 go1(m1);
  delay(500);
 go2(m2);
  delay(500);
 go3(m3);
  delay(500);
   
  Serial.println("Void_End");  
  delay(200);      

}

int go1( int t) // From a to b
{ int j,k;
  int temp=0, i;

  if( t < current1 ){
    j=0; // if j=0, Unwind
  }
  else if (t > current1){
    j=1;      // if j=1, wind-up
  }
  else {
    j=2;       // if j=2, Dont do anything
  }


  
      if(j==0){       //unwind
         
        digitalWrite(M11, LOW);
        digitalWrite(M12,HIGH);
      }
       else if(j==1){   //wind
        
        digitalWrite(M11, HIGH);
        digitalWrite(M12, LOW);
      }


      if(j==0){     //unwind
      while(abs(m1-current1)){     
        i=analogRead(3);
        Serial.println(i);
        if(i<700 && temp == 1){
          temp=0;
          current1--;
        }
        else if(i>700){
          temp=1;
        }
      }
      }

      
      if(j==1){         //wind
      while(abs(m1-current1)){     
        i=analogRead(3);
        Serial.println(i);
        if(i<700 && temp == 1){
          temp=0;
          current1++;
        }
        else if(i>700){
          temp=1;
        }
      }
      }
        digitalWrite(M11, LOW);
        digitalWrite(M12, LOW);
        
     
    if(j==0){
        delay(13);
        digitalWrite(M11, HIGH);    //wind-up a bit
        digitalWrite(M12, LOW);
        delay(13);
        digitalWrite(M11, LOW);
        digitalWrite(M12, LOW);          
    }
    
 
}

int go2( int t) // From a to b
{ int j,k;
  int temp=0, i;

  if( t < current2 ){
    j=0; // if j=0, Unwind
  }
  else if (t > current2){
    j=1;      // if j=1, wind-up
  }
  else {
    j=2;       // if j=2, Dont do anything
  }


  
      if(j==0){       //unwind
         
        digitalWrite(M21, LOW);
        digitalWrite(M22,HIGH);
      }
       else if(j==1){   //wind
        
        digitalWrite(M21, HIGH);
        digitalWrite(M22, LOW);
      }


      if(j==0){     //unwind

      while(abs(m2-current2)){     
        i=analogRead(2);
        Serial.println(i);
        if(i<700 && temp == 1){
          temp=0;
          current2--;
        }
        else if(i>700){
          temp=1;
        }
      }
      }
      if(j==1){         //wind

      while(abs(m2-current2)){     
        i=analogRead(2);
        Serial.println(i);
        if(i<700 && temp == 1){
          temp=0;
          current2++;
        }
        else if(i>700){
          temp=1;
        }
      }
      }
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
     
    if(j==0){
        delay(13);
        digitalWrite(M21, HIGH);    //wind-up a bit
        digitalWrite(M22, LOW);
        delay(13);
        digitalWrite(M21, LOW);
        digitalWrite(M22, LOW);
          
    }
    
 
}

int go3( int t) // From a to b
{ int j,k;
  int temp=0, i;

  if( t < current3 ){
    j=0; // if j=0, Unwind
  }
  else if (t > current3){
    j=1;      // if j=1, wind-up
  }
  else {
    j=2;       // if j=2, Dont do anything
  }


  
      if(j==0){       //unwind
         
        digitalWrite(M31, LOW);
        digitalWrite(M32,HIGH);
      }
       else if(j==1){   //wind
        
        digitalWrite(M31, HIGH);
        digitalWrite(M32, LOW);
      }


      if(j==0){     //unwind

      while(abs(m3-current3)){     
        i=analogRead(1);
        Serial.println(i);
        if(i<700 && temp == 1){
          temp=0;
          current3--;
        }
        else if(i>700){
          temp=1;
        }
      }
      }
      if(j==1){         //wind

      while(abs(m3-current3)){     
        i=analogRead(1);
        Serial.println(i);
        if(i<700 && temp == 1){
          temp=0;
          current3++;
        }
        else if(i>700){
          temp=1;
        }
      }
      }
        digitalWrite(M31, LOW);
        digitalWrite(M32, LOW);
     
    if(j==0){
        delay(13);
        digitalWrite(M31, HIGH);    //wind-up a bit
        digitalWrite(M32, LOW);
        delay(13);
        digitalWrite(M31, LOW);
        digitalWrite(M32, LOW);
          
    }
    
 
}


