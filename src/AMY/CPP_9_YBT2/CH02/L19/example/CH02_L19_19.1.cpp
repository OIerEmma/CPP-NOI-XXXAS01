//
// Created by Amy on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n % 4 == 0) cout << n / 4 << ' ' << n / 2;
    else
        if (n % 2 == 0) cout << n / 4 + 1 << ' ' << n / 2;
        else cout << 0 << ' ' << 0;
    return 0;
}