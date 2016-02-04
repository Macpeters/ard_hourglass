const int switchPin = 8;
//the time an led was last changed
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
//for counting which led is next
int led = 2;
//10 minutes = 600,000 ms
long interval = 60000;

void setup() {
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT); 
   }
   pinMode(switchPin, INPUT);
}

void loop() {
//  how long the arduino has been running
  unsigned long currentTime = millis();

  if(currentTime - previousTime > interval){
//    I feel like this will be off by a few ms, but we'll see
    previousTime = currentTime; 
    digitalWrite(led, HIGH);
    led++;
    if(led == 7){
//       do something
     }

     switchState = digitalRead(switchPin);

//    clock has been turned over - start counting from the start
     if(switchState != prevSwitchState){
      for(int x = 2; x < 8; x++){
        digitalWrite(x, LOW); 
       } 

      led = 2;
      previousTime = currentTime;
     }

     prevSwitchState = switchState;
  }
}
