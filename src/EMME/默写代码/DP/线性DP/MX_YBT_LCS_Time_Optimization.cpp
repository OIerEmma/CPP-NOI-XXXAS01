//
// Created by Emme.Kwok on 2026/9/6.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, maxn = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i], maxn = max(maxn, a[i]);
    for (int i = 0; i < n; i++) cin >> b[i], maxn = max(maxn, b[i]);
    vector<int> pos(maxn + 1, 0), lis;
    for (int i = 0; i < n; i++) pos[b[i]] = i + 1;
    for (int i = 0; i < n; i++) if (pos[a[i]]) lis.push_back(pos[a[i]]);
    vector<int> tails;
    for (int i = 0; i < lis.size(); i++) {
        auto it = lower_bound(tails.begin(), tails.end(), lis[i]);
        if (it == tails.end()) tails.push_back(lis[i]);
        else *it = lis[i];
    }
    cout << tails.size() << endl;
    return 0;
}