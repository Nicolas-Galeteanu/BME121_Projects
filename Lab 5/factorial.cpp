//
// Created by nicol on 2026-10-27.
//
#include<iostream>
using namespace std;


int main() {
    int input;
    int n = 1;
    cin>>input;

    if (input == 0) {
        cout<<"1"<<endl;
    }else if (cin.fail()||input <0) {
        return 1;
    }else {
        for (int i = 1; i <= input; i++) {
            n *= i;
        }
        cout<<"The factorial of" << input << " is "<<n<<"."<<endl;
    }
    return 0;
}