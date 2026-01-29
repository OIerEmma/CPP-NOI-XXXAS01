//
// Created by Emma on 2024/12/7.
//
#include<iostream>
using namespace std;

int main() {
    int timeB, timeW, d;
    cin >> d;
    timeB = 27 + 23 + d / 3.0;
    timeW = d / 1.2;
    if(timeB == timeW) {
        cout << "All";
    } else if(timeB > timeW){
        cout << "Walk";
    } else {
        cout << "Bike";
    }
        return 0;
}