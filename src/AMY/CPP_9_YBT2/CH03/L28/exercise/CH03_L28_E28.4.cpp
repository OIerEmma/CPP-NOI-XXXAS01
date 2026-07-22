//
// Created by Amy on 2026/7/6.
//
#include<bits/stdc++.h>
using namespace std;

bool a[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1, x; i < n; i++) {
        cin >> x;
        a[x] = true;
    }
    for (int i = 1; i <= n; i++) if (!a[i]) cout << i << endl, exit(0);
    return 0;
}