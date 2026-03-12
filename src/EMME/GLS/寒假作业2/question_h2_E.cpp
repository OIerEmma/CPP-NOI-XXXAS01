//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double n;
    cin >> n;
    if (n <= 3) {
        cout << "10.00";
    } else if (n <= 5) {
        int d = ceil(n - 3);
        printf("%.2lf", 10 + d * 1.8);
    } else {
        int d = ceil(n - 5);
        printf("%.2lf", 13.6 + d * 2.7);
    }
    return 0;
}