//
// Created by Emme.Kwok on 2026/9/29.
//
#include<bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    // freopen("seat.in", "r", stdin);
    // freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
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
    // cout << pos << endl;
    int i = 0, j = 1, line = 1, t = pos;
    while (pos) {
        if (line % 2) i++;
        else i--;
        if ((i > n || i < 1) && pos != t) j++, line++;
        else pos--;
        // cout << i << " " << j << endl;
    }
    cout << j << " " << i << "\n";
    return 0;
}