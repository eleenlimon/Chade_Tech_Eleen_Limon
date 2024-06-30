#ifndef MENU_H // Header guard to prevent multiple inclusion
#define MENU_H

// Function prototypes for the menu functions
void inputInitialTime(int &setHour, int &setMinute, int &setSecond); // Function to input the initial time from the user
void printMenu(); // Function to print the menu of options for the user
unsigned int getMenuChoice(unsigned int maxChoice); // Function to get the user's choice from the menu
void mainMenu(int &userChoice, int &setHour, int &setMinute, int &setSecond); // Function to handle the main menu and user choices

#endif // MENU_H
