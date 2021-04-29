/*     Arduino Rotary Encoder 
 *  
 */
 
 #define output1 5
 #define output2 6
 int counter = 0; 
 int aState;
 int aLastState;  
 void setup() { 
   pinMode (output1,INPUT);
   pinMode (output2,INPUT);
   
   Serial.begin (1000);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
 void loop() { 
   aState = digitalRead(outputA); // Reads current state of the outputA
   // If the previous != current state of the outputA, Pulse has occured
   if (aState != aLastState){     
     // If the outputB != the outputA state, encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of outputA
