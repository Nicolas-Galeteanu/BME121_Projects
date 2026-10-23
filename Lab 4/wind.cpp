/*
Lab 3
Room: E2 1792
File: wind.cpp
Course: SYDE/BME 121 – Digital Computation
Author: Nicolas Galeteanu (Student #21253379)
Purpose: Calculate the windchill based on the given temperature and wind speed
Date: 2025-10-20
*/

#include <cmath>
#include <iostream>
using namespace std;



int main() {
    //Declare variables
    double windSpeed; //The given wind speed
    double temperature; //The given temperature
    double windchill; //The calculated windchill

    //Set the precision of the outputs
    cout.setf(ios::fixed);
    cout.precision(2);

    //Get the wind speed and temperature from the user in degrees Celsius
    cout << "enter temperature and wind speed (Degrees Celsius): ";
    cin >> temperature;
    cin >> windSpeed;

    //Check if the input is valid
    if (cin.fail() || windSpeed <= 0) {
        return 1;
    }

    //Convert the temperature and wind speed to the empirical measurement system
    temperature = (temperature * 9/5) + 32;
    windSpeed /= 1.609;

    //Get the windchill from a given formula based on the wind speed
    if (windSpeed <= 4) {
        windchill = temperature;
    }else if (windSpeed <= 45) {
        windchill = 91.4 - (10.45 + 6.69 * sqrt(windSpeed) - 0.447*windSpeed) * (91.4 - temperature)/22;
    }
    else{
        windchill=1.6*temperature-55;
    }

    //convert the windchill to degrees centigrade
    windchill = 5*(windchill- 32)/9;

    //Output the windchill to the user
    cout<<"The wind chill index is " << windchill << ". Brrrr!" << endl;
}