//
// Created by Emme.Kwok on 2026/4/23.
//
#include<iostream>
using namespace std;

int f[1001];

int main() {
    int n;
    cin >> n;
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}