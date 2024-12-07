//
// Created by Emma on 2024/12/7.
//
#include<iostream>
using namespace std;

int main() {
    int weekday;
    cin >> weekday;
    switch(weekday) {
        case 1:
        case 3:
        case 5:
            cout << "NO";
            break;
        default:
            cout << "YES";
        return 0;
    }
}