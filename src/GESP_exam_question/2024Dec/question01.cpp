//
// Created by Emma on 2025/2/6.
//
#include<iostream>
using namespace std;

int main() {
    double k;
    scanf("%lf", &k);
    double c = k - 273.15, f = c * 1.8 + 32;
    if(f > 212.00) {
        printf("Temprature is too high!");
    } else {
        printf("%.2lf %.2lf", c, f);
    }
    return 0;
}
