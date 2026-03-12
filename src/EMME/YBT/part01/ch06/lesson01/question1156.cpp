//
// Created by Emma on 2025/2/22.
//
#include<iostream>
#include<cmath>
using namespace std;
double res = 1, x, pi;
int main() {
    double i = 1, s = 1;
    x = 1.0 / sqrt(3);
    while(res >= 0.000006) {
        res = pow(x, i) / i;
        pi += res * s;
        i += 2;
        s = -s;
    }
    res = pow(x, i) / i;
    pi += res * s;
    printf("%.10lf\n",  6 * pi);
    return 0;
}
