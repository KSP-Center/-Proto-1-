// vex library and namespace
#include "vex.h"
using namespace vex;

// main devices
brain   Brain;
controller Controller1 = controller (primary);

// drivetrain motors
// left side
motor left1 = motor (PORT1, ratio6_1, false);
motor left2 = motor (PORT1, ratio6_1, false);
motor left3 = motor (PORT1, ratio6_1, false);

// rightside
motor right1 = motor (PORT1, ratio6_1, true);
motor right2 = motor (PORT1, ratio6_1, true);
motor right3 = motor (PORT1, ratio6_1, true);

// drivetrain motor group
motor_group leftDrive = motor_group (left1, left2, left3);
motor_group rightDrive = motor_group (right1, right2, right3);

// other motors
motor conveyor = motor (PORT1, ratio18_1, false);
motor intake = motor (PORT1, ratio18_1, false);

// ai sensors
vision MainVision = vision (PORT1); // needs switching to ai vision once class is released
gps MainGPS = gps (PORT1);

// vision signatures (needs programming)
vision::signature RED = vision::signature (1, 0, 0, 0, 0, 0, 0, 3, 0);
vision::signature BLUE = vision::signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
vision::signature LIME = vision::signature (3, 0, 0, 0, 0, 0, 0, 3, 0);