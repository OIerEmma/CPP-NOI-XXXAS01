//
// Created by Geek.Kwok on 6/23/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> p[m + 1];
    for (int i = 0; i < n; i++) p[a[i]].push_back(b[i]);
    for (int i = 1; i <= m; i++) sort(p[i].begin(), p[i].end(), greater<int>());
    int count = 0;
    for (int i = 1; i <= m; i++) {
        int sum = 0;
        auto it = p[i].begin();
        while (sum < k && it != p[i].end()) { sum += *it; count++; ++it; }
        if (sum < k) { cout << -1 << endl; exit(0); }
    }
    cout << count << endl;
    return 0;
}