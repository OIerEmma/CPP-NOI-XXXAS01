//
// Created by Geek.Kwok on 2026/3/15.
//
#include <bits/stdc++.h>
using namespace std;

bool b[21];
int n, r, a[21];

void print() {
    for (int i = 1; i <= r; i++) {
        cout << setw(3) << a[i];
    }
    cout << endl;
}

void dfs(int step) {
    if (step > r) {
        print();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] || a[step - 1] > i) continue;
        a[step] = i;
        b[i] = true;
        dfs(step + 1);
        b[i] = false;
    }
}

int main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}