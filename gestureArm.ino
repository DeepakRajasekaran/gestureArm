#include <Servo.h>

#define stringLen 6

// Define finger Indexes

#define Thumb 0
#define Index 1
#define Middle 2
#define Ring 3
#define Pinky 4

//Define ---------------------------------

int finger_states[5];
int counter = 0;
bool CounterState = false;
String received;

// Define servo objects
Servo thumbServo;
Servo indexServo;
Servo middleServo;
Servo ringServo;
Servo pinkyServo;

// Define constants for finger states
const int FINGER_OPEN = 1;
const int FINGER_CLOSE = 0;

// Define Positions

const int Pos1 = 10;
const int Pos2 = 170;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Attach servos to pins
  thumbServo.attach(2);
  indexServo.attach(3);
  middleServo.attach(4);
  ringServo.attach(5);
  pinkyServo.attach(6);

  preset();

}

void preset(){
  // Set initial finger positions
  thumbServo.write(Pos2);
  indexServo.write(Pos1);
  middleServo.write(Pos1);
  ringServo.write(Pos1);
  pinkyServo.write(Pos2);
}

void receiveData() {
 if(Serial.available()){
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '#') {
      CounterState = true;
      received = "";
      counter = 0;
    }
//------------------------------------------------------------
    if (CounterState) {
      if (counter < stringLen) {
        received = String(received+c);
        counter++;
      }
    //  Serial.println(received);
      
//>> Issue fixed
      if (counter >= stringLen) {
        for (int i = 0; i < 5; i++) {
          finger_states[i] = received.substring(i+1,i+2).toInt();
        }
//------------------------------------------------------------------       
        CounterState = false;
        received = "";
        counter = 0;
        delay(10000);
      }
    }
  }
}
 else{
    for(int i = 0; i < 5; i++){finger_states[i] = 1;}
  }
}

void actuate(){
// Actuate fingers based on their states
    if (finger_states[Thumb] == FINGER_OPEN) {thumbServo.write(Pos2);} else if (finger_states[0] == FINGER_CLOSE) {thumbServo.write(Pos1);}

    if (finger_states[Index] == FINGER_OPEN) {indexServo.write(Pos1);} else if (finger_states[1] == FINGER_CLOSE) {indexServo.write(Pos2);}

    if (finger_states[Middle] == FINGER_OPEN) {middleServo.write(Pos1);} else if (finger_states[2] == FINGER_CLOSE) {middleServo.write(Pos2);}

    if (finger_states[Ring] == FINGER_OPEN) {ringServo.write(Pos1);} else if (finger_states[3] == FINGER_CLOSE) {ringServo.write(Pos2);}

    if (finger_states[Pinky] == FINGER_OPEN) {pinkyServo.write(Pos2);} else if (finger_states[4] == FINGER_CLOSE) {pinkyServo.write(Pos1);}
    
    delay(200);
    } 
  


void loop() {
  receiveData();
  actuate();
}
 