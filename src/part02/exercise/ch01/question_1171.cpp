//
// Created by Emma on 2025/8/12.
//
#include<iostream>
using namespace std;

char c[31];

int main() {
    bool flag = false;
    cin >> c;
    int len = (int)strlen(c), t;
    for (int k = 2; k <= 9; k++) {
        t = 0;
        for (int j = 1; j <= len; j++) {
            t = t * 10 + (c[j - 1] - 48);
            t %= k;
        }
        if (t == 0) {
            flag = true;
            cout << k << " ";
        }
    }
    if (!flag) {
        cout << "none" << endl;
    }
    return 0;
}