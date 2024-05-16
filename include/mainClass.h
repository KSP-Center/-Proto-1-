// libraries and namespace
#include "vex.h"
#include "classes.h"
using namespace vex;

// print the motor temps onto the brain
int mainClass::printTemp() {
    // setup the vairables
    tX = 50;
    tY = 50;
    r = 25;

    // being the printing process
    // print circle one of eight
    firstHue = left1.temperature(percent);
    convert ();
    Brain.Screen.drawCircle(tX, tY, r, secondHue);

    // print circle two of eight
    tX = tX + 75;
    firstHue = left2.temperature(percent);
    convert ();
    Brain.Screen.drawCircle(tX, tY, r, secondHue);

    // print circle three of eight
    tX = tX + 75;
    firstHue = left3.temperature(percent);
    convert ();
    Brain.Screen.drawCircle(tX, tY, r, secondHue);

    // print circle four of eight
    tX = tX - 150;
    tY = tY + 75;
    firstHue = right1.temperature(percent);
    convert ();
    Brain.Screen.drawCircle(tX, tY, r, secondHue);

    // print circle five of eight
    tX = tX + 75;
    firstHue = right2.temperature(percent);
    convert ();
    Brain.Screen.drawCircle(tX, tY, r, secondHue);

    // print circle six of eight
    tX = tX + 75;
    firstHue = right3.temperature(percent);
    convert();
    Brain.Screen.drawCircle(tX, tY, r, secondHue);

    return 0;
}

// convert the firstHue into the secondHue (secondary function)
int mainClass::convert() {
    if (firstHue <= 20) {
        secondHue = 120;
    } else if (firstHue >= 20 && firstHue <= 40) {
        secondHue = 60;
    } else if (firstHue >= 40 && firstHue <= 60) {
        secondHue = 30;
    } else if (firstHue >= 60 && firstHue <= 80) {
        secondHue = 0;
    } else if (firstHue >= 80) {
        secondHue = 330;
    } else if (firstHue == NULL) {
        secondHue = 270;
    }

    return 0;
}

// print the motor names on the circles
int mainClass::printMotorName() {
    // setup the variables
    tX = 25;
    tY = 60;

    Brain.Screen.printAt(tX, tY, "left1");
    tX = tX + 75;
    Brain.Screen.printAt(tX, tY, "left2");
    tX = tX + 75;
    Brain.Screen.printAt(tX, tY, "left3");

    return 0;
}

// setup the drivetrain for AI control
int mainClass::AISetup() {
    // setup the variables
    velocityRPM = 600;
    torquePer = 100;

    // set the parameters of the drivetrain
    leftDrive.setVelocity(velocityRPM, rpm);
    leftDrive.setMaxTorque(torquePer, percent);
    rightDrive.setVelocity(velocityRPM, rpm);
    rightDrive.setMaxTorque(torquePer, percent);

    return 0;
}

// moves the drivetrain when in manual mode
int mainClass::manualControl() {
    if (Controller1.Axis3.position() >= 25) {
        leftDrive.spin(forward);
        rightDrive.spin(forward);
    } else if (Controller1.Axis3.position() <= -25) {
        leftDrive.spin(reverse);
        rightDrive.spin(reverse);
    } else if (Controller1.Axis4.position() >= 25) {
        leftDrive.spin(forward);
        rightDrive.spin(reverse);
    } else if (Controller1.Axis4.position() <= -25) {
        leftDrive.spin(reverse);
        rightDrive.spin(reverse);
    }

    return 0;
}

// moves the drivetrain depending on the value of 'moveInt'
int mainClass::movement() {
    switch(moveInt) {
        case 0:
            leftDrive.stop();
            rightDrive.stop();
        case 1:
            leftDrive.spin(forward);
            rightDrive.spin(forward);
        case 2:
            leftDrive.spin(reverse);
            rightDrive.spin(reverse);
        case 3:
            leftDrive.spin(reverse);
            rightDrive.spin(forward);
        case 4:
            leftDrive.spin(forward);
            rightDrive.spin(reverse);
    }

    return 0;
}

// store the objects detected by the vision sensor
int mainClass::visionCount() {
    // store red object count
    MainVision.takeSnapshot(RED);
    redCount = MainVision.objectCount;

    // store blue object count
    MainVision.takeSnapshot(BLUE);
    blueCount = MainVision.objectCount;

    // store lime object count
    MainVision.takeSnapshot(LIME);
    limeCount = MainVision.objectCount;

    return 0;
}

// kills all robot components and sets lowest possible settings (use for testing)
int mainClass::pauseCommand() {
    // setup kill command number
    killNumber = 0;

    // stop the drivetrain
    leftDrive.stop();
    rightDrive.stop();

    // set the velocity and torque of drivetrain to 0
    leftDrive.setVelocity(killNumber, percent);
    leftDrive.setMaxTorque(killNumber, percent);
    rightDrive.setVelocity(killNumber, percent);
    rightDrive.setMaxTorque(killNumber, percent);

    // stop the intake and conveyor
    intake.stop();
    conveyor.stop();

    // set the velocity and torque of both motors to 0
    intake.setVelocity(killNumber, percent);
    intake.setMaxTorque(killNumber, percent);
    conveyor.setVelocity(killNumber, percent);
    conveyor.setMaxTorque(killNumber, percent);

    return 0;
}

// checks for the installed components
int mainClass::checkComponents() {
    // print the components name and 'if installed' number
    for (loopInt = 0; loopInt < 9; ++loopInt) {
        printf("\n", componentName);
        printf("\b", component2);

        component1 = component1 + 1;
    }
    component1 = 0;


    return 0;
}

int mainClass::checkNumber() {
    switch (component1) {
        case 1:
            component2 = left1.installed();
            componentName = "left1 = ";
        case 2:
            component2 = left2.installed();
            componentName = "left2 = ";
        case 3:
            component2 = left3.installed();
            componentName = "left3 = ";
        case 4:
            component2 = right1.installed();
            componentName = "right1 = ";
        case 5:
            component2 = right2.installed();
            componentName = "right2 = ";
        case 6:
            component2 = right3.installed();
            componentName = "right3 = ";
        case 7:
            component2 = MainVision.installed();
            componentName = "vision = ";
        case 8:
            component2 = MainGPS.installed();
            componentName = "gps = ";
        case 9:
            component2 = Controller1.installed();
            componentName = "controller = ";
    }

    return 0;
}