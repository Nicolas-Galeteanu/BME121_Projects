/*
Lab 3
Room: E2 1792
File: wdhms.cpp
Course: SYDE/BME 121 – Digital Computation
Author: Nicolas Galeteanu (Student #21253379)
Purpose: Calculate the number of weeks, days, minutes, and seconds given a number of seconds: i.e. 100 000 seconds is
0 weeks, 1 day, 3 hours, 46  minutes, and 40 seconds
Date: 2025-10-20
*/


#include <iostream>
using namespace std;



int main() {
    int remainder; //The remaining number of seconds as given by the user

    //Get the number of seconds the user wants to convert
    cout<<"Enter the number of seconds: ";
    cin >> remainder;

    //Check if the input is valid
    if (cin.fail() || remainder <= 0) {
        return 1;
    }

    //Calculate the number of weeks from the given number of seconds
    const int WEEKS = remainder / 604800; // The number of weeks
    //Calculate the remaining seconds
    remainder %= 604800;

    //Calculate the number of days from the remaining seconds
    const int DAYS = remainder/86400; //The number of days
    //Calculate the remaining seconds
    remainder %= 86400;

    //Calculate the number of hours from the remaining seconds
    const int HOURS = remainder/3600; //The number of hours
    //Calculate the remaining seconds
    remainder %= 3600;

    //Calculate the number of minutes from the remaining hours
    const int MINUTES = remainder/60; //The number of minutes
    //Calculate the remaining seconds
    remainder %= 60;

    const int SECONDS = remainder; //The remaining seconds


    //Output the calculated values
    cout << WEEKS << " weeks, \n"
<< DAYS << " days, \n"
<< HOURS << " hours, \n"
<< MINUTES<< " minutes and \n"
<< SECONDS << " seconds.\n";

}