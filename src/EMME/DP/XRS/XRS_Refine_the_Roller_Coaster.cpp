//
// Created by Emme.Kwok on 2026/8/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> up(n), down(n);
    vector<long long> tails;
    tails.clear();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), h[i]);
        up[i] = (int)(it - tails.begin()) + 1;
        if (it == tails.end()) tails.push_back(h[i]);
        else *it = h[i];
    }
    tails.clear();
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(tails.begin(), tails.end(), h[i]);
        down[i] = (int)(it - tails.begin()) + 1;
        if (it == tails.end()) tails.push_back(h[i]);
        else *it = h[i];
    }
    int ans = 0;
    for (int k = 1; k <= n - 2; k++)
        if (up[k] >= 2 && down[k] >= 2)
            ans = max(ans, up[k] + down[k] - 1);
    cout << n - ans << endl;
    return 0;
}