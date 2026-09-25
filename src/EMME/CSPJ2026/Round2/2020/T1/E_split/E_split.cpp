//
// Created by Emme.Kwok on 2026/9/23.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("E_split.in", "r", stdin);
    // freopen("E_split.out", "w", stdout);
    int n;
    cin >> n;
    if (n & 1) cout << "-1\n", exit(0);
    int i = 1;
    vector<int> ans;
    while (n) {
        if (n & 1) ans.push_back(1 << i - 1);
        n >>= 1;
        i++;
    }
    for (int id = (int)ans.size() - 1; id >= 0; id--) {
        cout << ans[id];
        if (id != 0) cout << " ";
    }
    return 0;
}