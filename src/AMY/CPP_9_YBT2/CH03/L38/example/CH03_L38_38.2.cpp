//
// Created by Amy on 2026/7/17.
//
#include<bits/stdc++.h>
using namespace std;
int n;
char c;
int main() {
    cin >> c >> n;
    if (c == 'L') {
        for (int i = 1, sp = n - 1, st = 1; i < n; i++, sp--, st += 2) {
            cout << setw(sp) << setfill(' ') << ' ';
            cout << setw(st) << setfill('*') << '*';
            cout << endl;
        }
        cout << setw(2 * n - 1) << setfill('*') << '*' << endl;
        for (int i = n - 1, sp = 1; i >= 1; i--, sp++) {
            cout << setw(sp) << setfill(' ') << ' ';
            cout << setw(2 * i - 1) << setfill('*') << '*';
            cout << endl;
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            cout << setw(n) << setfill('*') << '*';
            cout << endl;
        }
    }
    return 0;
}