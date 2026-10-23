/*
Lab 2
Room: E2 1792
File: lab0202.cpp
Course: SYDE/BME 121 – Digital Computation
Author: Nicolas Galeteanu (Student #21253379)
Purpose: Find the number of boxes of pencils, pens, and white out needed for The Write Stuff
Date: 2025-10-02
*/


#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;


int main()
{
    // Initializing Constants

    // The number of office supplies their respective containers can hold
    const double PEN_BOX_SIZE = 10;
    const double PENC_BOX_SIZE = 25;
    const double CF_BOTTLE_SIZE = 200;

    // The number of pens each individual employee needs
    const double JR_PEN_REQUIREMENT = 7;
    const double SR_PEN_REQUIREMENT = 3;
    const double ADMIN_PEN_REQUIREMENT = 6;

    // The number of pencils each individual employee needs
    const double JR_PENC_REQUIREMENT = 8;
    const double SR_PENC_REQUIREMENT = 5;
    const double ADMIN_PENC_REQUIREMENT = 2;

    // The amount of correction fluid each individual employee needs
    const double JR_CF_REQUIREMENT = 60;
    const double SR_CF_REQUIREMENT = 12;
    const double ADMIN_CF_REQUIREMENT = 40;

    // Declaring variables

    //the total number of employees
    double total_employees;

    // Percentages of different types of employees
    double jr_percent;
    double sr_percent;
    double adminPercent;    

    // The head count of different types of employees
    double jr_number;
    double sr_number;
    double admin_number;

    // The number of pens each type of employee needs total
    double jr_pens;
    double sr_pens;
    double admin_pens;

    // The number of pencils each type of employee needs total
    double jr_penc;
    double sr_penc;
    double admin_penc;

    // The amount of correction fluid each type of employee needs total
    double jr_CF;
    double sr_CF;
    double admin_CF;

    // The total number of office supplies needed
    double total_pens;
    double total_penc;
    double total_CF;

    // The total number of containers of the office supplies needed
    double pen_box;
    double penc_box;
    double cf_bottle;



    // Get the total number of employees from the user
    cout << "Enter the total number of employees: ";
    cin >> total_employees;

    // Get the percentage of jr. engineers from the user
    cout << "Enter the percentage (0-100) of Jr. Engineers: ";
    cin >> jr_percent;

    // Get the percentage of sr. engineers from the user
    cout << "Enter the percentage (0-100) of SR. Engineers: ";
    cin >> sr_percent;

    // Calculate the percentage of admin employees
    adminPercent = 100 - jr_percent - sr_percent;

    // Calculate the number of each type of employee using their respective percentage
    jr_number = total_employees * jr_percent / 100;
    sr_number = total_employees * sr_percent / 100;
    admin_number = total_employees * adminPercent / 100;


    // Calculate the total number of pens required for each type of employee
    jr_pens = jr_number * JR_PEN_REQUIREMENT;
    sr_pens = sr_number * SR_PEN_REQUIREMENT;
    admin_pens = admin_number * ADMIN_PEN_REQUIREMENT;

    // Calculate the total amount of correction fluid required for each type of employee
    jr_CF = jr_number * JR_CF_REQUIREMENT;
    sr_CF = sr_number * SR_CF_REQUIREMENT;
    admin_CF = admin_number * ADMIN_CF_REQUIREMENT;

    // Calculate the total number of pencils required for each type of employee
    jr_penc = jr_number * JR_PENC_REQUIREMENT;
    sr_penc = sr_number * SR_PENC_REQUIREMENT;
    admin_penc = admin_number * ADMIN_PENC_REQUIREMENT;

    // Calculate total number of each type of office supply
    total_pens = jr_pens + sr_pens + admin_pens;
    total_penc = jr_penc + sr_penc + admin_penc;
    total_CF = jr_CF + sr_CF + admin_CF;

    // Calculate the total number of container for each type of office supply
    pen_box = ceil(total_pens / PEN_BOX_SIZE);
    penc_box = ceil(total_penc / PENC_BOX_SIZE);
    cf_bottle = ceil(total_CF / CF_BOTTLE_SIZE);

    // Output the amount of containers for each type of office supply
    cout << "You need:\n"
        << pen_box << " Boxes of Pens\n"
        << penc_box << " Boxes of Pencils\n"
        << cf_bottle << " Bottles of Correction Fluid";
}
