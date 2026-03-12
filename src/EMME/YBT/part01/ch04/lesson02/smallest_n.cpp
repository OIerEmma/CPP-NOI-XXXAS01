//
// Created by Emma on 2025/1/1.
//
#include<iostream>
using namespace std;

int main() {
    int i = 0 , m;
    double s = 0;
    cin >> m;
    while (s < m) {
        ++i;
        s += 1.0 / i;
    }
    cout << i << endl;
    return 0;
}