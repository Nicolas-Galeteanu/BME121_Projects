//
// Created by nicol on 2026-10-27.
//

#include<iostream>
using namespace std;

int main() {
    int size;
    int n = 0;
    int i = 0;


    cin >> size;


    if (cin.fail() || size%2 != 0 || size<=0) {
        return 1;
    }

    while (n<size) {
        i = 0;
        while (i<size) {
            if (n == 0 || n==size-1 || i == 0 || i==size-1) {
                cout << "*";
            }
            else {
                cout << " ";
            }

            if (i != size-1) {
                cout<<' ';
            }
            i++;
        }
        cout << endl;
        n++;
    }


    return 0;
}