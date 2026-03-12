//
// Created by Emme.Kwok on 2026/2/1.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int maxx = 0, minn = 1e9 + 1;
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        maxx = max(maxx, a);
        minn = min(minn, a);
    }
    cout << maxx - minn << endl;
    return 0;
}