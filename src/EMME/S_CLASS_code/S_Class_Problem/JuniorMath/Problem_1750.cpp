//
// Created by Emme.Kwok on 2025/9/21.
//
#include<iostream>
using namespace std;

int main() {
    int k, n = 2;
    double sn = 1.0;
    cin >> k;
    while (sn <= k) {
        sn += 1.0 / n;
        n++;
    }
    cout << n - 1 << endl;
    return 0;
}