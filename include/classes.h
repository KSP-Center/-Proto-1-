#ifndef mainClass
#include "devices.h"

// computing class
class mainClass {
    // printTemp variables
    int tX;
    int tY;
    int r;
    float firstHue;
    float secondHue;

    // drivetrain variables
    int velocityRPM;
    int torquePer;

    // drivetrain movement number
    int moveInt;

    // vision sensor object counts
    int redCount;
    int blueCount;
    int limeCount;

    // kill command default number
    int killNumber;

    // check function variables
    bool componentInstalled;
    int loopInt;
    int component1;
    int component2;
    char const* componentName;

public:
    // standing functions
    int movement();
    int visionCount();

    // computing functions
    int printTemp();
    int printMotorName();
    int convert();

    // manualAI functions
    int AISetup();
    int manualControl();

    // extra functions
    int pauseCommand();
    int checkComponents();
    int checkNumber();

};

#endif