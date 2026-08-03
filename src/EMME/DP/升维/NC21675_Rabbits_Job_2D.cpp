//
// Created by Emme.Kwok on 2026/7/29.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<long long>> pre(n + 1, vector<long long>(n + 1, 1e9));
    vector<vector<long long>> cur(n + 1, vector<long long>(n + 1, 1e9));
    pre[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= i; w++) {
            for (int c = 0; c <= n; c++) cur[w][c] = 1e9;
            for (int c = 0; c <= w; c++) cur[w][0] = min(cur[w][0], pre[w][c]);
            if (s[i - 1] == '1')
                for (int c = 1; c <= w; c++) cur[w][c] = min(cur[w][c], pre[w - 1][c - 1] + c);
        }
        pre.swap(cur);
    }
    for (int w = n; w >= 0; w--)
        for (int c = 0; c <= w; c++)
            if (pre[w][c] <= k) cout << w << endl, exit(0);
    return 0;
}