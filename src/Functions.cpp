#include "functions.h"
#include "DriveFunctionsConfig.h"
#include "vex.h"

void testPID()
{
  for(int i = 0; i < 8; i++)
  {
    moveLinear(12, 100, 10000);  
    moveRotate(-90, 90, 10000);
  }
  //moveStop();
  wait(20, msec); // Sleep the task for a short amount of time t
}

// catapult spin function: input number of shots, motor velocity (always 100), (unused) timeout time
void cataSpin(float shots, int velocity, uint32_t timeOut) {
  // Converts number of shots to number of roitations (4:1 gear ratio)
  int rotations = shots * 4;
  Cata1.rotateFor(-rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
  Cata2.rotateFor(-rotations, rotationUnits::rev, velocity, velocityUnits::pct, true);
}
