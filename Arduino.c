// Arduino Rotary Encoder 
 
 #define output1 5
 #define output2 6
 int counter = 0; 
 int aState;
 int alastState;  
 void setup() { 
   pinMode (output1,INPUT);
   pinMode (output2,INPUT);
   
   Serial.begin (1000);
   // Reads the initial state of the first output
   aLastState = digitalRead(output1);   
 } 
 void main() { 
  // Get current state of the first output
   aState = digitalRead(output1); 
   // If the previous is not the same as the current state of the first output
   if (aState != aLastState){     
     // If the outputB != the outputA state, encoder is rotating clockwise
     if (digitalRead(outputB) == aState) { 
       counter --;
     } else {
       counter ++;
     }
   } 
  // Updates the previous state of frst output
   aLastState = aState; 
