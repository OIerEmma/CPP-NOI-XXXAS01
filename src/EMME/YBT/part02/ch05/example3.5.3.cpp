//
// Created by Emme.Kwok on 2026/1/3.
//
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n, a[30];

void dfs(int step, int num) {
    if (num == 0) {
        cout << n << "=";
        for (int i = 1; i < step - 1; i++) {
            cout << a[i] << "+";
        }
        cout << a[step - 1] << endl;
        return;
    }
    for (int i = a[step - 1]; i <= num; i++) {
        if (i < n) {
            a[step] = i;
            // cout << a[step] << " ";
            dfs(step + 1, num - i);
        }
    }
}

int main() {
    cin >> n;
    a[0] = 1;
    dfs(1, n);
    return 0;
}
