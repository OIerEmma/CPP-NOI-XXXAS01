//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    while(q--) {
        int L, R;
        cin >> L >> R;
        cout << pre[R] - pre[L - 1] << '\n';
    }
    return 0;
}