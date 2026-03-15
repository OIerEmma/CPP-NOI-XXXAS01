//
// Created by Geek.Kwok on 2026/3/15.
//
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a[100005]={1}, n;

void print(int t) {
    cout << n << "=";
    for (int i = 1; i <= t - 1; i++) {
        cout << a[i] << "+";
    }
    cout << a[t] << endl;
}

void dfs(int step, int t) {
    if (step == 0) {
        print(t - 1);
        return;
    }

    for (int i = a[t - 1]; i <= step; i++) {
        if (i >= n) continue;
        a[t] = i;
        step -= i;
        dfs(step, t + 1);
        step += i;
    }
}

int main() {
    cin >> n;
    dfs(n, 1);
    return 0;
}