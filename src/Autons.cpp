#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

//add function prototypes for auton routines here
void noAuton();
void Auton1();
void Auton2();

//add function names and function pointers here
//follow the existing sytax, replacing the string
//with function name to show on the controller screen
autonsTuple autons[] = {{"NONE",    &noAuton},
                        {"AUTON_1", &Auton1},
                        {"AUTON_2", &Auton2}};

const uint8_t numAutons = sizeof(autons)/sizeof(autonsTuple);


//Put your auton routines in here
void noAuton()
{
  //dummy function for running no auton
  //LEAVE IN PLACE!
}

void Auton1() {
  moveLinear(32, 75, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveLinear(-32, 75, 2000);
  moveStop(coast);
  wait(1000, msec);
  flaps.open();
  moveLinear(22, 75, 2000);
  moveStop(coast);
  flaps.close();
  moveLinear(-18, 75, 2000);
  moveRotate(120, 75, 2000);
  moveLinear(36, 75, 2000);
  flaps.open();
}

void Auton2() {
  moveLinear(36, 80, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveLinear(-3, 75, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveRotate(-80, 75, 2000);
  moveLinear(48, 75, 2000);
  flaps.open();
  moveRotate(40, 75, 2000);

}