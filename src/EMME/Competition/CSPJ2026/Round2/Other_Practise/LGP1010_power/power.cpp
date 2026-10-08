//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

void calc(int n) {
    int p = (int)pow(2, 14);
    for (int i = 14; i >= 0; i--) {
        if (p <= n) {
            if (i == 1) cout << "2";
            else if (i == 0) cout << "2(0)";
            else {
                cout << "2(";
                calc(i);
                cout << ")";
            }
            n -= p;
            if (n != 0) cout << "+";
        }
        p /= 2;
    }
}

int main() {
    int n;
    cin >> n;
    calc(n);
    return 0;
}