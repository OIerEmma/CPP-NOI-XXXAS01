//
// Created by Emma on 2025/2/4.
//
#include<iostream>
using namespace std;

int main() {
    int distanse;
    cin >> distanse;
    double const biketime = (27 + 23 + distanse) * 1.0 / 3.0;
    double const walktime = distanse * 1.0 / 1.2;
    if(biketime > walktime) {
        printf("Walk");
    } else if(walktime > biketime) {
        printf("Bike");
    } else {
        printf("All");
    }
    return 0;
}