// Project One: Chada Tech
// Developer: Eleen Limon
// This program outputs 2 clocks (12-hour and 24-hour) and allows the user to
// manipulate the clocks by adding increments of hours/minutes/seconds.


#include "Menu.h" // Including the header file for menu functionality
#include "Clock.h" // Including the header file for clock functionality
#include <iostream>
#include <string>
#include <limits>

using namespace std;

extern int currentHour; // Declaration of current hour variable
extern int currentMinute; // Declaration of current minute variable
extern int currentSecond; // Declaration of current second variable

// Main function to initialize and run the clock program
int main() {
    int userChoice = 0;

    // Input the initial time
    inputInitialTime(currentHour, currentMinute, currentSecond);

    // Main loop to display clocks and handle menu choices
    while (userChoice != 4) {
        printClockBorder(); // Printing the border for the clock display
        printClocks(currentHour, currentMinute, currentSecond); // Printing the clock display
        printClockBorder(); // Printing the border for the clock display
        printMenu(); // Printing the menu options
        mainMenu(userChoice, currentHour, currentMinute, currentSecond); // Handling menu choices
    }

    return 0;
}