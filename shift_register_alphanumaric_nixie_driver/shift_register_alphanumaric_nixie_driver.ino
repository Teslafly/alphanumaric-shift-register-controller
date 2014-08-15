//based on modified example code to drive shift registers.
//This program drives alphanumaric displays using shift registers. Originally developed to drive alphanumaric nixie tubes and involves no charlieplexing.
// code does not currently work.


//constants and other settings.
//////////////////////////////////////////////////////////////////////////

//pins
#define shiftSER  8   //pin 14 on the 75HC595
#define shiftRCLK 9   //pin 12 on the 75HC595
#define shiftSRCLK 10 //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 2 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8



//variables for use in program
//////////////////////////////////////////////////////////////////////////

boolean registers[numOfRegisterPins];
int NextChar;



//subroutines
//////////////////////////////////////////////////////////////////////////

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


//setup. Runs once at microcontroller boot
//////////////////////////////////////////////////////////////////////////

void setup(){
  pinMode(shiftSER, OUTPUT);
  pinMode(shiftRCLK, OUTPUT);
  pinMode(shiftSRCLK, OUTPUT);

  Serial.begin(9600);
  
  //reset all register pins
  clearRegisters();
  writeRegisters();
}               



// loop, runs infinately after microcontroller completes setup
//////////////////////////////////////////////////////////////////////////

void loop(){

  
  // for reference only, remove before releasing code.
  /*
  // pin3
    if( digitalRead(in2) == LOW) {
    setRegisterPin(2, HIGH);
  } else  {
    setRegisterPin(2, LOW);
  }  
 */
 
 
 if (Serial.available() > 0) { // send charecter to NextChar 
    // get incoming byte:
    NextChar = Serial.read(); // 
 }
 
   // set array to segment values of charecter for NextChar and shiftout if newline is sent
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

  writeRegisters();  //should be called in it's own case. segments should otherwise be added to registers until then.
  
  
  
  delay(100);
}
