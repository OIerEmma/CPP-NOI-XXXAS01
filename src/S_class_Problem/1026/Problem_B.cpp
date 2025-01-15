//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    double a, S;
    cin >> a;
    if (a > 0) {
        S = a * a;
        printf("%.2lf", S);
    } else {
        cout << "NO";
    }
    return 0;
}
