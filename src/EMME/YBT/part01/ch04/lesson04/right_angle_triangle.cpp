//
// Created by Emma on 2025/1/3.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int x = 1; x <= i; x ++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}