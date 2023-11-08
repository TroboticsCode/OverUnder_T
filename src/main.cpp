// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial12           inertial      12              
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       JBormann                                                  */
/*    Created:      Nov. 2019                                                 */
/*    Description:  Trobotics Template File                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  initDriveMotors();
  
  Controller1.ButtonR1.pressed(cycle_autons);
  Brain.Screen.pressed(cycle_autons);
  return;
}

void autonomous(void) 
{
  auton_runner();
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) { 
  //add local user control variables here:
  // Sets velocities andf braking for catapult and intake motors
  Cata1.setVelocity(100, percent);
  Cata2.setVelocity(100, percent);
  Intake.setVelocity(100, percent);
  Cata1.setStopping(coast);
  Cata2.setStopping(coast);
  Intake.setStopping(coast);

  // Unnecesarily opens and closes solenoids (so does nothing)
  flaps.open();
  flaps.close();

  intake.open();
  intake.close();

  balance.open();
  balance.close();

  // Initializes cataSpin (wether catapult is on) to false
  bool cataSpin = false;
  //User control code here, inside the loop:
  //remove existing demo code and replace with you own! Then remove this comment
  while (1) {
   // Catapult control - on / off switch
    if (Controller1.ButtonR1.pressing()) {
      // Turns on catapult when R1 is pressed
      cataSpin = true;
      // Extends intake when catapult spins so they don't hit each other
      intake.open();
    } else if (Controller1.ButtonR2.pressing()) {
      // Turns off catapult when R2 is pressed
      cataSpin = false;
    }
    
    // Catapult control - Motor controll
    if (cataSpin == true) {
      // Turns on catapult motors when cataSpin is on
      Cata1.spin(reverse);
      Cata2.spin(reverse);
    } else {
      // Turns off catapult motors when cataSpin is off
      Cata1.stop();
      Cata2.stop();
    }

    // Flap control
    if (Controller1.ButtonL1.pressing()) {
      // Opens flaps when L1 is pressed
      flaps.open();
    }
    if (Controller1.ButtonL2.pressing()) {
      // Closes flaps when Ls is pressed
      flaps.close();
    }

    // Intake control
    if (Controller1.ButtonRight.pressing()) {
      // Runs intake inward when Front Left Scuff is pressed
      Intake.spin(directionType::fwd);
      // Extends intake automaticaly - speeds up intake process
      intake.open();
    } else if (Controller1.ButtonY.pressing()) {
      // Runs intake outward when Front Right Scuff is pressed
      Intake.spin(reverse);
      // Extends intake automaticaly - speeds up intake process
      intake.open();
    } else {
      // Stops intake otherwise
      Intake.stop();
    }

    // Intake extension control
    if (Controller1.ButtonB.pressing()) {
      // Extends intake when Bottom Right Scuff is pressed
      intake.open();
    }
    if (Controller1.ButtonDown.pressing()) {
      // Retracts intake when ottom Left Scuff is pressed
      intake.close();
    }

    // banacing arm control
    if (Controller1.ButtonA.pressing() && Controller1.ButtonLeft.pressing()) {
      // Extends the catapult arm only if A and LEFT are pressed
      // irreversible, prevents accideltal operation
      balance.open();
    }

    // Sleep the task for a short amount of time to
    //leave the drive code here, it should work if you set up 
    // DriveFunctionsConfig.h properly
    userDrive();

    wait(20, msec); // Sleep the task for a short amount of time to
  }
}


// Main will set up the competition functions and callbacks.

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
