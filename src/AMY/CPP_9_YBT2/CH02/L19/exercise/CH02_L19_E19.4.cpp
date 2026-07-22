//
// Created by Amy on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;
double b, w, r;
int main() {
    cin >> r;
    b = 50 + r / 3.0;
    w = r / 1.2;
    if (b > w) {
        cout << "Walk";
    }
    if (w > b) {
        cout << "Bike";
    }
    if (w == b) {
        cout << "All";
    }
    return 0;
}
