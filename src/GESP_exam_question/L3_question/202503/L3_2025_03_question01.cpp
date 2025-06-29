//
// Created by Emma on 2025/6/27.
//
#include<iostream>
using namespace std;

int main() {
    int x;
    bool flag = true;
    cin >> x;
    for (int i = 1; i <= 2025; i++) {
        if ((x & i) + (x | i) == 2025) {
            flag = false;
            cout << i << endl;
            break;
        }
    }
    if (flag) {
        cout << -1 << endl;
    }
    return 0;
}