//
// Created by Geek.Kwok on 6/23/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    int ans = 1e9;
    do {
        int len = n;
        for (int i = 1; i < n; i++) len += max(a[p[i]], b[p[i-1]]);
        ans = min(ans, len);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}