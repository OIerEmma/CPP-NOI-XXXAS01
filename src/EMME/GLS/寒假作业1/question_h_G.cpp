//
// Created by Emme.Kwok on 2026/1/23.
//
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    double a = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    double b = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
    double c = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    double p = (a + b + c) / 2;
    cout << fixed << setprecision(2) << sqrt(p * (p - a) * (p - b) * (p - c));
    return 0;
}