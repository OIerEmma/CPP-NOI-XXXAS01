//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    double a;
    cin >> a;
    if (a > 0) {
        printf("%.2lf", a * a);
    } else {
        cout << "NO";
    }
    return 0;
}