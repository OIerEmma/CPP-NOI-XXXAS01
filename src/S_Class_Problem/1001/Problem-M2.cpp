//
// Created by Emma on 2025/1/22.
//
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if((a >= 60) && (b >= 60)) {
        cout << "0";
    } else {
        if (a <= 60 && b <= 60) {
            cout << "0";
        } else {
            cout << "1";
        }
    }
    return 0;
}