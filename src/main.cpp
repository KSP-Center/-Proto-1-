/*
This is the main code program for Proto-1. The robot consists
of a six motor, 600 RPM @ 2.75in wheel drivetrain. Other additions
incude a intake and conveyor.
Note: The program is named 'Proto-1b' because the Windows compilers
were being a douche on 'Proto-1'.
*/

// libraries and namespace
#include "vex.h"
#include "mainClass.h"
using namespace vex;

// main program
int main() {
    // initialize extra variables
    bool manualMode;
    int repeat;

    // create the class
    mainClass main;

    // setup the extra variables for startup
    manualMode = true;
    repeat = 99999999;

    // execute the program    
    while (true) {

        // manual mode (starts in this by default)
        if (manualMode == true) {
            // setup the repeat variable
            repeat = 99999999;

            for (repeat = 0; repeat <= repeat - 1; ++repeat) {
                main.manualControl();
                main.printTemp();
                main.printMotorName();

                // allows for switching between manual and AI mode
                if (Controller1.ButtonL2.pressing() == true && Controller1.ButtonR2.pressing() == true) {
                    repeat = 0;
                    manualMode = false;
                }

                // executes the check functions
                if (Controller1.ButtonL1.pressing() == true && Controller1.ButtonR1.pressing() == true) {
                    main.checkComponents();
                }

                // completes the kill command until the B button on the controller is released
                if (Controller1.ButtonLeft.pressing() == true) {
                    while (Controller1.ButtonB.pressing()) {
                        main.pauseCommand();
                    }
                }
                wait (200, msec);
            }
        }

        // AI mode
        if (manualMode == false) {
            // setup the repeat variable
            repeat = 99999999;

            // setup the AI function
            main.AISetup();

            for (repeat = 0; repeat <= repeat - 1; ++repeat) {
                // print out the circles and names of the motors and motor temps
                main.printTemp();
                main.printMotorName();

                // AI code goes here

                // allows for switching between manual and AI mode
                if (Controller1.ButtonA.pressing() == true) {
                    repeat = 0;
                    manualMode = true;
                }

                // executes the check functions
                if (Controller1.ButtonL1.pressing() == true && Controller1.ButtonR1.pressing() == true) {
                    main.checkComponents();
                }

                // completes the pause command until the B button on the controller is released
                if (Controller1.ButtonB.pressing() == true) {
                    while (Controller1.ButtonB.pressing()) {
                        main.pauseCommand();
                    }
                }
            }
        }
    }
}