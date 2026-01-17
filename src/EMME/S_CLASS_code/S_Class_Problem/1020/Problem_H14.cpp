//
// Created by Emma on 2025/8/8.
//
#include<iostream>
using namespace std;

int t[10], tmax[10];

int main() {
    int a, b, count = 0, week = 0;
    for (int i = 0; i < 7; i++) {
        cin >> a >> b;
        t[i] = a + b;
    }
    for (int i = 0; i < 7; i++) {
        if (t[i] > 8) {
            tmax[i] = t[i];
            count++;
        } else {
            tmax[i] = 0;
        }
    }
    int v = tmax[0];
    if (count == 0) {
        cout << 0 << endl;
    } else if (count > 0) {
        for (int i = 0; i < 7; i++) {
            if (v < tmax[i]) {
                v = tmax[i];
                week = i + 1;
            }
        }
    }
    cout << week << endl;
    return 0;
}
