#include "Clock.h" // Include the Clock header file
#include "Menu.h" // Include the Menu header file
#include <iostream> // Include the input/output stream library
#include <iomanip> // Include the input/output manipulator library

using namespace std; // Use the standard namespace

int currentHour = 0; // Initialize the current hour variable to 0
int currentMinute = 0; // Initialize the current minute variable to 0
int currentSecond = 0; // Initialize the current second variable to 0

// Function to generate a string with 'length' repetitions of character 'ch'
string nCharString(size_t length, char ch) {
    return string(length, ch); // Return a string with specified length and character
}

// Function to format an integer into a two-digit string
string twoDigitString(int n) {
    return (n < 10) ? "0" + to_string(n) : to_string(n); // Return a string with the integer formatted as two digits
}

// Function to format time in 24-hour format
string formatTime24(int h, int m, int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); // Return the time in 24-hour format
}

// Function to format time in 12-hour format
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string time; // Declare a string variable to store the formatted time
    if (h == 0) {
        time = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " AM"; // Format time for midnight (12:00 AM)
    } else if (h < 12) {
        time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " AM"; // Format time for morning
    } else if (h == 12) {
        time = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " PM"; // Format time for noon (12:00 PM)
    } else {
        time = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " PM"; // Format time for afternoon/evening
    }
    return time; // Return the formatted time
}

// Function to print the border of the clock display
void printClockBorder() {
    cout << nCharString(27, '*') << "     " << nCharString(27, '*') << endl; // Print the border with asterisks
}

// Function to print the clock display
void printClocks(int hours, int minutes, int seconds) {
    int hourConv = hours; // Initialize a variable to hold the converted hour value
    string amPm = "AM"; // Initialize a variable to hold the AM/PM indicator
    if (hours == 0) {
        hourConv = 12; // Convert hour 0 to 12 for 12-hour format
    } else if (hours == 12) {
        amPm = "PM"; // Change indicator to PM for noon
    } else if (hours > 12) {
        hourConv = hours - 12; // Convert hours greater than 12 to 12-hour format
        amPm = "PM"; // Set PM indicator for afternoon/evening
    }
    cout << "*      12-Hour Clock      *     *      24-Hour Clock      *" << endl; // Print clock type header
    cout << "*      " << twoDigitString(hourConv) << ":" << twoDigitString(minutes) << ":" << twoDigitString(seconds) << " " << amPm << "        *     *      " << formatTime24(hours, minutes, seconds) << "           *" << endl; // Print formatted time in both 12-hour and 24-hour formats
}

// Function to get the current hour
int getHour() {
    return currentHour; // Return the current hour
}

// Function to set the current hour
void setHour(int hour) {
    currentHour = hour; // Set the current hour to the specified value
}

// Function to get the current minute
int getMinute() {
    return currentMinute; // Return the current minute
}

// Function to set the current minute
void setMinute(int minute) {
    currentMinute = minute; // Set the current minute to the specified value
}

// Function to get the current second
int getSecond() {
    return currentSecond; // Return the current second
}

// Function to set the current second
void setSecond(int second) {
    currentSecond = second; // Set the current second to the specified value
}

// Function to add one second to the time
void addOneSecond() {
    int currentSecond = getSecond(); // Get the current second
    if (currentSecond >= 0 && currentSecond < 59) {
        setSecond(currentSecond + 1); // Increment the second by 1 if it's within the valid range
    } else if (currentSecond == 59) {
        setSecond(0); // Reset the second to 0 if it's 59 and add one minute
        addOneMinute(); // Call the function to add one minute
    }
}

// Function to add one minute to the time
void addOneMinute() {
    int currentMinute = getMinute(); // Get the current minute
    if (currentMinute >= 0 && currentMinute < 59) {
        setMinute(currentMinute + 1); // Increment the minute by 1 if it's within the valid range
    } else if (currentMinute == 59) {
        setMinute(0); // Reset the minute to 0 if it's 59 and add one hour
        addOneHour(); // Call the function to add one hour
    }
}

// Function to add one hour to the time
void addOneHour() {
    int currentHour = getHour(); // Get the current hour
    if (currentHour >= 0 && currentHour < 23) {
        setHour(currentHour + 1); // Increment the hour by 1 if it's within the valid range
    } else if (currentHour == 23) {
        setHour(0); // Reset the hour to 0 if it's 23
    }
}