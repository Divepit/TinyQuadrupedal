#include <Servo.h> 

// INITIALIZE SERVOS
Servo shoulder1;
Servo foot1;
Servo shoulder2;
Servo foot2;
Servo shoulder3;
Servo foot3;
Servo shoulder4;
Servo foot4;

int shoulder_fl = 90;
int shoulder_fr = 90;
int shoulder_br = 90;
int shoulder_bl = 90;
int foot_fl = 180;
int foot_fr = 0;
int foot_br = 0;
int foot_bl = 180;

int writeServos () {
  shoulder1.write(shoulder_fl);
  foot1.write(foot_fl);
  shoulder2.write(shoulder_fr);
  foot2.write(foot_fr);
  shoulder3.write(shoulder_br);
  foot3.write(foot_br);
  shoulder4.write(shoulder_bl);
  foot4.write(foot_bl);
}

//SINGLE LEG FUNCTIONS

void frontL(int shoulder, int foot) {
  switch(shoulder) {
    case 0:
    shoulder_fl = 90;
    break;
    case 1:
    shoulder_fl = 135;
    break;
    case 2:
    shoulder_fl = 180;
  }
  switch(foot) {
    case 0:
    foot_fl = 180;
    break;
    case 1:
    foot_fl = 135;
    break;
    case 2:
    foot_fl = 90;
  }
}


//LEG POSITIONS

int flat () {
  shoulder_fl = 90;
  shoulder_fr = 90;
  shoulder_br = 90;
  shoulder_bl = 90;
  foot_fl = 90;
  foot_fr = 90;
  foot_br = 90;
  foot_bl = 90;
  writeServos();
}

int standStraight () {
  shoulder_fl = 90;
  shoulder_fr = 90;
  shoulder_br = 90;
  shoulder_bl = 90;
  foot_fl = 180;
  foot_fr = 0;
  foot_br = 0;
  foot_bl = 180;
  writeServos();
}

int standStraightOutside() {
  shoulder_fl = 180;
  shoulder_fr = 0;
  shoulder_br = 180;
  shoulder_bl = 0;
  foot_fl = 180;
  foot_fr = 0;
  foot_br = 0;
  foot_bl = 180;
  writeServos();
}

int standReady () {
  shoulder_fl = 90;
  shoulder_fr = 90;
  shoulder_br = 135;
  shoulder_bl = 45;
  foot_fl = 180;
  foot_fr = 0;
  foot_br = 25;
  foot_bl = 155;
  writeServos();
}

int bendOver () {
  shoulder_fl = 135;
  shoulder_fr = 45;
  foot_fl = 115;
  foot_fr = 65;
  writeServos();
}

int straightenFR () {
  shoulder_fr = 90;
  foot_fr = 0;
  writeServos();
}
int fullAdvanceFR () {
  shoulder_fr = 0;
  foot_fr = 30;
  writeServos();
}

int straightenBL () {
  shoulder_bl = 90;
  foot_bl = 180;
  writeServos();
}
int fullAdvanceBL () {
  shoulder_bl = 0;
  foot_bl = 150;
  writeServos();
}

int straightenFL () {
  shoulder_fl = 90;
  foot_fl = 180;
  writeServos();
}
int fullAdvanceFL () {
  shoulder_fl = 180;
  foot_fl = 150;
  writeServos();
}

int straightenBR () {
  shoulder_br = 90;
  foot_br = 30;
  writeServos();
}
int fullAdvanceBR () {
  shoulder_br = 180;
  foot_br = 0;
  writeServos();
}

//ANIMATIONS

int pushUps (int amount) {
  for(int i = 0; i < amount; i++){
    standReady();
    delay(150);
    bendOver();
    delay(200);
    standReady();
    delay(150);
  }
}

int stepOne(int speed) {
  fullAdvanceBL();
  straightenFR();
  delay(speed);
  fullAdvanceFR();
  straightenBL();
  delay(speed);
  straightenFR();
}

int stepTwo(int speed) {
  fullAdvanceBR();
  straightenFL();
  delay(speed);
  fullAdvanceFL();
  straightenBR();
  delay(speed);
  straightenFL();
}

int walk(int speed, int steps) {
  for(int i = 0; i < steps; i++){
    stepOne(speed);
    stepTwo(speed); 
  }
}
void setup() 
{ 
  shoulder1.attach(2);
  foot1.attach(3);
  shoulder2.attach(4);
  foot2.attach(5);
  shoulder3.attach(7);
  foot3.attach(8);
  shoulder4.attach(10);
  foot4.attach(9);
  pushUps(5);
  standStraight();
  delay(1000);
  walk(150,5);
} 

void loop() {

  } 
