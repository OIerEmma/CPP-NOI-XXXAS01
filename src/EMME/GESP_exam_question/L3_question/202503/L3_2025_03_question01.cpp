//
// Created by Emma on 2025/6/27.
//
#include<iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    bool flag = false;
    for (int y = 0; y < 2025; y++) {
        if ((x & y) + (x | y) == 2025) {
            cout << y << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << -1;
    }
    return 0;
}