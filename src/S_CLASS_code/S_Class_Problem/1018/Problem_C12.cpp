//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

int main() {
    double s = 0;
    int m, i = 1;
    cin >> m;
    while (s <= m) {
        s += double(1.0 / i);
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}