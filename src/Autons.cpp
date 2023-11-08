#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

//add function prototypes for auton routines here
void noAuton();
void Auton1();
void Auton2();
void Auton3();
void Auton4();

//add function names and function pointers here
//follow the existing sytax, replacing the string
//with function name to show on the controller screen
autonsTuple autons[] = {{"NONE",    &noAuton},
                        {"AUTON_1", &Auton1},
                        {"AUTON_2", &Auton2},
                        {"AUTON_3", &Auton3},
                        {"AUTON_4", &Auton4}
                        };

const uint8_t numAutons = sizeof(autons)/sizeof(autonsTuple);


//Put your auton routines in here
void noAuton()
{
  //dummy function for running no auton
  //LEAVE IN PLACE!
}

void Auton1() 
{
  // Push triball into goal
  moveLinear(18, 75, 2000);
  moveStop(brake);
  wait(1000, msec);
  // Move back from goal
  moveLinear(-32, 75, 2000);
  moveStop(coast);
  wait(1000, msec);
  // Open flaps
  flaps.open();
  // Push triball out from load zone using flaps
  moveLinear(22, 75, 2000);
  moveStop(coast);
  // Cose flaps
  flaps.close();
  // Move under elevation post
  moveLinear(-18, 75, 2000);
  moveRotate(120, 75, 2000);
  moveLinear(36, 75, 2000); 
  // Open flaps to touch elevation post
  flaps.open();
  
  // Other program idea
  /*
  moveLinear(32, 75, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveRotate(180, 100, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveLinear(32, 75, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveRotate(-45, 100, 2000);
  moveStop(coast);
  wait(1000, msec);
  moveLinear(48, 70, 4000);*/

}

// Auton routine 2: match far side
void Auton2() 
{
  // Push triball into goal
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

// Auton routine 3: simple skills
void Auton3() 
{
  // Push triball into goal
  intake.open();
  // Push triball into goal
  moveLinear(-1, 100, 2000);
  cataSpin(70, 100, 100000);
}

// Auton routine 4: complex skills
void Auton4(void) 
{
  // Open intake to make room for launcher
  intake.open();
  // move up against match load bar
  moveLinear(-1, 100, 2000);
  // Shoot 40 triballs
  cataSpin(40, 100, 40000);
  // Close intakes
  intake.close();
  // Various moves to move to the other side of thge field, 
  // line up in front of the goal up against the long barrier
  moveLinear(-2, 100, 2000);
  wait(500,  msec);
  moveLinear(6, 100, 2000);
  wait(500,  msec);
  moveRotate(75, 100, 2000);
  wait(500,  msec);
  moveLinear(8, 100,  2000);
  wait(1000,  msec);
  moveRotate(-60, 100,  2000);
  wait(1000,  msec);
  moveLinear(70, 100, 3000);
  wait(500,  msec);
  moveRotate(-90, 100,  2000);
  wait(500,  msec);
  moveLinear(24, 100,  2000);
  wait(500,  msec);
  moveRotate(-30, 100,  2000);
  wait(500,  msec);
  moveLinear(24, 100,  2000);
  wait(500,  msec);
  moveRotate(135, 100,  2000);
  wait(500,  msec);
  // Open flaps
  flaps.open();
  // Push triballs into goal
  moveLinear(18, 100,  2000);
}