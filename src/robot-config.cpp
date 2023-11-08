#include "vex.h"
#include "DriveFunctionsConfig.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor Cata1 = motor(PORT11, ratio18_1, false);
motor Cata2 = motor(PORT12, ratio18_1, false);
motor Intake = motor(PORT10, ratio18_1, false);

pneumatics flaps = pneumatics(Brain.ThreeWirePort.A);
pneumatics intake = pneumatics(Brain.ThreeWirePort.B);
pneumatics balance = pneumatics(Brain.ThreeWirePort.C);

// VEXcode generated functions


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}