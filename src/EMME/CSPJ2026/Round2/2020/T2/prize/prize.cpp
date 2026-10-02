//
// Created by Emme.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

int b[605];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, w, a;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        b[a]++;
        int x = max(1, i * w / 100);
        for (int j = 600; j >= 0; j--) {
            x -= b[j];
            if (x <= 0) {
                cout << j << " ";
                break;
            }
        }
    }
    return 0;
}
/*
10 60
200 300 400 500 600 600 0 300 200 100
*/