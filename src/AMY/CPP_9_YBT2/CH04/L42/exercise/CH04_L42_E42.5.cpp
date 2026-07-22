//
// Created by Amy on 2026/7/22.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h, r;
    cin >> h >> r;
    const double PI = 3.14159;
    const int TARGET = 20000;
    double volume = PI * r * r * h;
    int buckets = ceil(TARGET / volume);
    cout << buckets << endl;
    return 0;
}
