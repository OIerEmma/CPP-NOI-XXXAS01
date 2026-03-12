//
// Created by Emme.Kwok on 2026/1/31.
//
#include<iostream>
using namespace std;

int a[10005], s[105];

int main() {
    int n, r;
    cin >> n >> r;
    int cnt = 0, minx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (cnt == r + 1) {
            cnt = 1;
        }
        s[cnt] += a[i];
    }
    for (int i = 1; i <= r; i++) {
        minx = max(s[i], minx);
        cout << s[i] << endl;
    }
    cout << minx << endl;
    return 0;
}