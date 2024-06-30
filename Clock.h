#ifndef CLOCK_H
#define CLOCK_H

#include <string>

using namespace std;

// Declare global variables
extern int currentHour; // Declaration of global variable for current hour
extern int currentMinute; // Declaration of global variable for current minute
extern int currentSecond; // Declaration of global variable for current second

// Function prototypes for clock functionality
string nCharString(size_t length, char ch); // Function prototype for generating a string with 'length' repetitions of character 'ch'
string twoDigitString(int n); // Function prototype for formatting an integer into a two-digit string
string formatTime24(int h, int m, int s); // Function prototype for formatting time in 24-hour format
string formatTime12(unsigned int h, unsigned int m, unsigned int s); // Function prototype for formatting time in 12-hour format
void printClockBorder(); // Function prototype for printing the border of the clock display
void printClocks(int hours, int minutes, int seconds); // Function prototype for printing the clock display

// Time manipulation functions
int getHour(); // Function prototype for getting the current hour
void setHour(int hour); // Function prototype for setting the current hour
int getMinute(); // Function prototype for getting the current minute
void setMinute(int minute); // Function prototype for setting the current minute
int getSecond(); // Function prototype for getting the current second
void setSecond(int second); // Function prototype for setting the current second
void addOneSecond(); // Function prototype for adding one second to the time
void addOneMinute(); // Function prototype for adding one minute to the time
void addOneHour(); // Function prototype for adding one hour to the time

#endif // CLOCK_H
