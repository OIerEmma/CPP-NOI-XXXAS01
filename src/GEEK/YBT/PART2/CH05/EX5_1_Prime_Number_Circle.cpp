//
// Created by Geek.Kwok on 2026/3/15.
//
#include <bits/stdc++.h>
using namespace std;

bool b[31];
int a[31], total, n;

void print() {
    total++;
    // cout << "<" << total << ">";
    for (int j = 1; j <= n; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
}

bool pd(int x, int y) {
    int sum = x + y;
    if (sum < 2) return false;
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) return false;
    }
    return true;
}

void dfs(int step) {
    if (step > n) {
        if (pd(a[n], a[1])) {
            print();
            exit(0);
        }
        // return;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] || !pd(a[step - 1], i)) continue;
        a[step] = i;
        b[i] = 1;
        dfs(step + 1);
        b[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1);
    // cout << total << endl;
}