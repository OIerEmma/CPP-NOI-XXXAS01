//
// Created by Emme.Kwok on 2026/9/30.
//
#include<bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    int r = a[1], pos = 0;
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= n * m; i++)
        if (a[i] == r) {
            pos = i;
            break;
        }
    int j = ceil(pos * 1.0 / n);
    cout << j << " " << (j % 2 ? (pos - 1) % n + 1 : n - (pos - 1) % n) << endl;
    return 0;
}