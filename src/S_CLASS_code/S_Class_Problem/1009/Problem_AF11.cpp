//
// Created by Emma on 2025/7/31.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int space = 0, xing = n;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        for (int j = 1; j <= xing; j++) {
            cout << "* ";
        }
        cout << endl;
        space++;
        xing--;
    }
    for (int i = 1; i <= space; i++) {
        cout << " ";
    }
    cout << "*" << endl;
    for (int i = 1; i < n; i++) {
        space--;
        xing++;
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        for (int j = 1; j <= xing; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}