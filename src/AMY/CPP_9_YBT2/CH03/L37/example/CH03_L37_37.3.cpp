//
// Created by Amy on 2026/7/16.
//
#include<bits/stdc++.h>
using namespace std;
int n, sp, c;
int main() {
    cin >> n;
    sp = n - 1;
    c = 1;
    for (int i = 1; i <= n; i++, sp--, c += 2) {
        for (int j = 1; j <= sp; j++) cout << ' ';
        for (int j = 1; j <= c; j++) cout << j;
        cout << endl;
    }
    sp = 1;
    c -= 4;
    for (int i = 1; i <= n; i++, sp++, c -= 2) {
        for (int j = 1; j <= sp; j++) cout << ' ';
        for (int j = 1; j <= c; j++) cout << j;
        cout << endl;
    }
    return 0;
}
