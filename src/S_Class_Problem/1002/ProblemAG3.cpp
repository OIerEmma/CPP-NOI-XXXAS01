//
// Created by Emma on 2025/2/13.
//
#include<iostream>
using namespace std;

int main() {
    int h, times = 10;
    double meters = 0.0, h10 = 0.0;
    cin >> h;
    h10 = h;
    while (times --) {
        meters += h10 * 2;
        h10 /= 2;
    }
    cout << meters - h << endl << h10 << endl;
    return 0;
}