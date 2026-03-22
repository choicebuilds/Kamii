#define DS1 PB12
#define DS2 PB13
#define DS3 PB14
#define DS4 PB11
#define DS5 PB10
#define LS1 PB6
#define LS2 PB7
#define MA1 PA2
#define MA2 PA3
#define MB1 PB9
#define MB2 PB8
#define led1 PA8
#define led2 PA15
#define led3 PB3
#define led4 PB4
#define led5 PB5
#define led6 PA1
#define led7 PA0
#define SW1 PA4
#define SW2 PA5
#define SW3 PA6
#define SW4 PA7

int dv1;
int dv2;
int dv3;
int dv4;
int dv5;
int lv1;
int lv2;
int strategy;
int currentState;
int previousState;

//SETUP
int getStrategy() {
  int b0 = !digitalRead(SW1);
  int b1 = !digitalRead(SW2);
  int b2 = !digitalRead(SW3);
  int b3 = !digitalRead(SW4);
  return (b3 << 3) | (b2 << 2) | (b1 << 1) | b0;
}
enum States {
  IDLE,
  SEARCH,
  ATTACK
};

// MOVEMENT
void forwards() {
  analogWrite(MA1, 0);
  analogWrite(MA2, 50);
  analogWrite(MB1, 50);
  analogWrite(MB2, 0);
}
void backwards() {
  analogWrite(MA1, 50);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 50);
}
void turnLeft () {
  analogWrite(MA1, 50);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 0);
}
void turnRight() {
  analogWrite(MA1, 0);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 50);
}
void brake() {
  analogWrite(MA1, 0);
  analogWrite(MA2, 0);
  analogWrite(MB1, 0);
  analogWrite(MB2, 0);
}
void charge() {
  analogWrite(MA1, 0);
  analogWrite(MA2, 255);
  analogWrite(MB1, 255);
  analogWrite(MB2, 0);
}

// HELPFUL
void getReadings() {
  dv1 = digitalRead(DS1);
  dv2 = digitalRead(DS2);
  dv3 = digitalRead(DS3);
  dv4 = digitalRead(DS4);
  dv5 = digitalRead(DS5);
  lv1 = digitalRead(LS1);
  lv2 = digitalRead(LS2);
}

void setup() {
  pinMode(DS1, INPUT);
  pinMode(DS2, INPUT);
  pinMode(DS3, INPUT);
  pinMode(DS4, INPUT);
  pinMode(DS5, INPUT);
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);

  strategy = getStrategy();
  currentState = ATTACK;
  digitalWrite(led2, LOW);
}

void loop() {
  switch(strategy) {
    case (0):
      switch (currentState) {
        case (ATTACK):
          forwards();
          delay(100);
          getReadings();
          while (dv3) {
            delay(100);
            getReadings();
          }
          currentState = SEARCH;
        case (SEARCH):
          brake();
          getReadings();
          if (dv1 || dv2) {
            turnLeft();
            getReadings();
            while (!dv3) {
              delay(100);
              getReadings();
            }
            brake();
            delay(100);
            currentState = ATTACK;
          }
          else if (dv4 || dv5) {
            turnRight();
            getReadings();
            while (!dv3) {
              delay(100);
              getReadings();
            }
            brake();
            delay(100);
            currentState = ATTACK;
          }
        }
    default:
      brake();
      delay(100000);
  }
}