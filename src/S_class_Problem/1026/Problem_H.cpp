//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    int year, month;
    cin >> year >> month;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        cout << year << "-" << month << "-" << 30 << endl;
    } else {
        if (month == 2) {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                cout << year << "-" << month << "-" << 29 << endl;
            } else {
                cout << year << "-" << month << "-" << 28 << endl;
            }
        } else {
            cout << year << "-" << month << "-" << 31 << endl;
        }
    }
    return 0;
}
