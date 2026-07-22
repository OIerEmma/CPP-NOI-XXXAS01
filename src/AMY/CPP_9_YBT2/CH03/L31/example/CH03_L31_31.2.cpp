//
// Created by Amy on 2026/7/10.
//
#include<bits/stdc++.h>
using namespace std;
int score, n, x, cnt;
int main() {
    cin >> score >> n;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        if (x > score) cnt++;
    }
    if (cnt + 1 <= n * 0.1) cout << "A";
    else if (cnt + 1 <= n * 0.3) cout << "B";
    else if (cnt + 1 <= n * 0.6) cout << "C";
    else if (cnt + 1 <= n * 0.8) cout << "D";
    else cout << "E";
    return 0;
}