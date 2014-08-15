int shiftSER = 8;   //pin 14 on the 75HC595
int shiftRCLK = 9;  //pin 12 on the 75HC595
int shiftSRCLK = 10; //pin 11 on the 75HC595


//How many of the shift registers - change this
#define number_of_74hc595s 2 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;
  }
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(shiftRCLK, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(shiftSRCLK, LOW);

    int val = registers[i];

    digitalWrite(shiftSER, val);
    digitalWrite(shiftSRCLK, HIGH);

  }
  digitalWrite(shiftRCLK, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}





void setup(){
  pinMode(shiftSER, OUTPUT);
  pinMode(shiftRCLK, OUTPUT);
  pinMode(shiftSRCLK, OUTPUT);

  Serial.begin(9600);
  
  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


void loop(){

  
  // pin3
    if( digitalRead(in2) == LOW) {
    setRegisterPin(2, HIGH);
  } else  {
    setRegisterPin(2, LOW);
  }  
 
   // set array to segment values of charecter for NextChar
  switch (NextChar) {
    
    ///////////////////////  
    case 0:
 
      break;  
    ///////////////////////   
    case 1:
      
      break;
    ///////////////////////   
    case 2:
      
      break;
    ///////////////////////   
    case 3:
 
      break;
    /////////////////////// 
    case 4:
 
      break;  
    ///////////////////////  
    case 5:
 
      break;
    ///////////////////////  
    case 6:
 
      break;
    ///////////////////////  
    case 7:
 
      break;
    ///////////////////////  
    case 8:
 
      break;
    ///////////////////////  
    case 9:
 
      break;
    ///////////////////////  
    case a:
 
      break;
    ///////////////////////  
    case b:
 
      break;
    ///////////////////////  
    case c:
 
      break;
      default: 
      // if nothing else matches, do the default
      // default is all segments on
  }

  writeRegisters();  //MUST BE CALLED TO ADD LETTER TO REGISTERS
  
  
  
  delay(100);
}
