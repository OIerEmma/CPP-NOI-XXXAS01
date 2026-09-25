//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

int apple(int n, int m) {
    if (n < 0 || m < 0) return 0;
    if (n <= 1 || m <= 1) return 1;
    return apple(n, m - 1) + apple(n - m, m);
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << apple(n, m) << "\n";
    }
    return 0;
}