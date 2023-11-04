#include <IRremote.h>
const int switch_1 = 7;
const int switch_2 = 8;
const int switch_3 = 9;
const int switch_4 = 10;
int RECV_PIN = 11;

int toggleState_1 = 0;
int toggleState_2 = 0;
int toggleState_3 = 0;
int toggleState_4 = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(switch_1, OUTPUT);
  pinMode(switch_2, OUTPUT);
  pinMode(switch_3, OUTPUT);
  pinMode(switch_4, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)){

    switch(results.value){
      case 0xFFA25D:
        if(toggleState_1 == 0){
          digitalWrite(switch_1, HIGH);
          toggleState_1 = 1;
        }
        else{
          digitalWrite(switch_1, LOW);
          toggleState_1 = 0;
        }
        delay(100);
      break;
      case 0xFF629D:
        if(toggleState_2 == 0){
          digitalWrite(switch_2, HIGH);
          toggleState_2 = 1;
        }
        else{
          digitalWrite(switch_2, LOW);
          toggleState_2 = 0;
        }
        delay(100);
      break;
      case 0xFFE21D:
        if(toggleState_3 == 0){
          digitalWrite(switch_3, HIGH);
          toggleState_3 = 1;
        }
        else{
          digitalWrite(switch_3, LOW);
          toggleState_3 = 0;
        }
        delay(100);
      break;
      case 0xFF22DD:
        if(toggleState_4 == 0){
          digitalWrite(switch_4, HIGH);
          toggleState_4 = 1;
        }
        else{
          digitalWrite(switch_4, LOW);
          toggleState_4 = 0;
        }
        delay(100);
      break;
      default : break;
    }

    irrecv.resume();
  }

}
