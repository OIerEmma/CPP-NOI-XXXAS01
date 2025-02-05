//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, count = 0, week;
    int time[7], Tmax[7];
    for (int i = 0; i < 7; i++) {
        cin >> a >> b;
        time[i] = a + b;
    }
    for (int i = 0; i < 7; i++) {
        if (time[i] > 8) {
            Tmax[i] = time[i];
            count++;
        } else {
            Tmax[i] = 0;
        }
    }
    int v = Tmax[0];
    if (count == 0) {
        cout << 0 << endl;
    } else if (count > 0){
        for (int i = 0; i < 7; i++) {
            if (v < Tmax[i]) {
                v = Tmax[i];
                week = i + 1;
            }
        }
    }
    cout << week << endl;
    return 0;
}
