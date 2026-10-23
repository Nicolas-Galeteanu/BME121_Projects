/*
File: lab0202.cpp
Course: SYDE/BME 121 – Digital Computation
Author: Nicolas Galeteanu (Student #21253379)
Purpose: Find the number of boxes of pencils, pens, and white out needed for The Write Stuff
based on given data
Date: 2025-09-12
*/
#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;


//initializing variables and constants:

double static totalEmployees;

///Stores Employee stats in this order:<p>
/// index 0: Number of Employees<p>
/// index 1: Number of Pencils per Employee<p>
/// index 2: Number of Pens per Employee<p>
/// index 3: Amount of Correction Fluid per Employee in mL<p>
double static jr_nums[4]= {0, 8, 7, 60};

///Stores Employee stats in this order:<p>
/// index 0: Number of Employees<p>
/// index 1: Number of Pencils per Employee<p>
/// index 2: Number of Pens per Employee<p>
/// index 3: Amount of Correction Fluid per Employee in mL<p>
double static sr_nums[4] = {0, 5, 3, 12};

///Stores Employee stats in this order:<p>
/// index 0: Number of Employees<p>
/// index 1: Number of Pencils per Employee<p>
/// index 2: Number of Pens per Employee<p>
/// index 3: Amount of Correction Fluid per Employee in mL<p>
double static admin_nums[4] = {0, 2, 6, 40};

///The size of the boxes in this order:<p>
/// index 0: Number of Pencils per box<p>
/// index 1: Number of Pens per box<p>
/// index 2: Amount of Correction Fluid per box in mL<p>
const double static BOX_SIZES[3] = {25, 10, 200};

///Stores the number of boxes in this order:<p>
/// index 0: Number of Pencil boxes<p>
/// index 1: Number of Pen boxes<p>
/// index 2: Amount of Correction Fluid boxes<p>
int static boxNum[3];


/// Sets the number of Employees using inputs given by the user
static void setNumberOfEmployees() {
    //gets the total number of employees from the user
    cout <<"Enter the number of employees: ";
    cin >> totalEmployees;
    bool pass = false;
    // Gets the percentage of jr and sr engineers from the user ensuring that the sum of them is between 0 and 100
    while (!pass) {
        cout<<"Enter the % of Jr. Engineers: ";
        cin>>jr_nums[0];
        cout<<"Enter the % of Sr. Engineers: ";
        cin>>sr_nums[0];
        if (100 >= jr_nums[0]+sr_nums[0] && 0<=jr_nums[0]+sr_nums[0]) {
            pass = true;
        } else {
            cout<<"Invalid input, please ensure that you input the number of employees as a percentage\n\n";
        }
    }

    //turns the percentages given into a number of employees
    jr_nums[0]/=100;
    sr_nums[0]/=100;
    admin_nums[0] = 1-jr_nums[0] - sr_nums[0];
    sr_nums[0]*=totalEmployees;
    jr_nums[0]*=totalEmployees;
    admin_nums[0]*=totalEmployees;
}

/// Finds the number of boxes based on the number of each type of employee
static void findNumOfBoxes(){
    /// Stores the number of boxes in this order:<p>
    /// index 0: Number of Pencils<p>
    /// index 1: Number of Pens<p>
    /// index 2: Amount of Correction Fluid in mL<p>
    double totalSupplies[3];

    //finds the number of each supply for each type of employee
    for (int i = 1; i < 4; i++) {
        jr_nums[i]*=jr_nums[0];
        sr_nums[i]*=sr_nums[0];
        admin_nums[i]*=admin_nums[0];
    }

    //finds the total of each supply and turns those values into number of boxes
    for (int i = 0; i < 3; i++) {
        totalSupplies[i] = jr_nums[i+1]+sr_nums[i+1]+admin_nums[i+1];
        boxNum[i] = ceil(totalSupplies[i]/BOX_SIZES[i]);
    }
}

///Runs
int main() {
    setNumberOfEmployees();
    findNumOfBoxes();
    cout<<"You need: "<<endl <<boxNum[0] <<" boxes of pencils\n"
    <<boxNum[1]<< " boxes of pens\n"
    << boxNum[2] << " bottles of correction fluid\n";
}