#include "Menu.h" // Include the header file for Menu functions
#include "Clock.h" // Include the header file for Clock functions
#include <iostream> // Include input/output stream library
#include <string> // Include string library
#include <limits> // Include limits library for numeric limits

using namespace std;

// Function to input the initial time from the user
void inputInitialTime(int &setHour, int &setMinute, int &setSecond) {
    string inputString;
    bool validTime = false;
    int firstColonPosition, secondColonPosition;

    while (!validTime) {
        cout << "Enter time as HH:MM:SS in 24-hour format: ";
        getline(cin, inputString); // Get input from the user
        firstColonPosition = inputString.find(':'); // Find the position of the first colon
        secondColonPosition = inputString.find(':', firstColonPosition + 1); // Find the position of the second colon
        try {
            // Convert substrings to integers for hour, minute, and second
            setHour = stoi(inputString.substr(0, firstColonPosition));
            setMinute = stoi(inputString.substr(firstColonPosition + 1, secondColonPosition - firstColonPosition - 1));
            setSecond = stoi(inputString.substr(secondColonPosition + 1));
        } catch (const exception &) {}
        // Check if the input format is valid and within range
        if (inputString.size() != 8 || setHour < 0 || setHour > 23 || setMinute < 0 || setMinute > 59 || setSecond < 0 || setSecond > 59) {
            cout << "Time is invalid" << endl;
        } else {
            validTime = true;
        }
    }
}

// Prints the menu of options for the user
void printMenu() {
    // Define menu items
    const char* menuItems[] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
    unsigned int numItems = sizeof(menuItems) / sizeof(menuItems[0]);
    unsigned char width = 26;

    // Print the menu items
    cout << nCharString(width, '*') << endl;
    for (unsigned int i = 0; i < numItems; i++) {
        string menuItem = string(menuItems[i]);
        unsigned int itemNumber = i + 1;
        unsigned int numSpaces = width - 8 - menuItem.length();
        string spaces = nCharString(numSpaces, ' ');
        cout << "* " << itemNumber << " - " << menuItem << spaces << " *" << endl;
        if (i != numItems - 1) {
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;
}

// Function to get the user's choice from the menu
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    do {
        cout << "Enter your choice (1-" << maxChoice << "): ";
        cin >> choice; // Get user choice
    } while (choice < 1 || choice > maxChoice); // Validate user choice
    return choice;
}

// Main menu function to handle user choices
void mainMenu(int &userChoice, int &setHour, int &setMinute, int &setSecond) {
    cout << "Select option (1-4): ";
    if (!(cin >> userChoice)) { // Check if input is not valid
        cin.clear(); // Clear the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        userChoice = 0; // Set user choice to 0
    }
    // Switch statement to handle user choice
    switch (userChoice) {
        case 1:
            cout << "1 hour added" << endl;
            addOneHour(); // Add one hour to the time
            break;
        case 2:
            cout << "1 minute added" << endl;
            addOneMinute(); // Add one minute to the time
            break;
        case 3:
            cout << "1 second added" << endl;
            addOneSecond(); // Add one second to the time
            break;
        case 4:
            cout << "Goodbye!" << endl; // Exit the program
            break;
        default:
            cout << "Invalid choice. Enter a number between 1-4..." << endl; // Invalid input message
            cin.clear(); // Clear the input stream
            break;
    }
}