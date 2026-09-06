//
// Created by Emme.Kwok on 2026/7/19.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, maxn = -1;
    cin >> n >> m;
    vector<int> s1(n), s2(n);
    for (int i = 0; i < n; i++) cin >> s1[i], maxn = max(maxn, s1[i]);
    for (int i = 0; i < m; i++) cin >> s2[i], maxn = max(maxn, s2[i]);
    vector<int> pos(maxn + 1, 0), a, tails;
    // 标记两个字符串中都存在的字符
    for (int i = 0; i < m; i++) pos[s2[i]] = i + 1;
    for (int i = 0; i < n; i++)
        if (pos[s1[i]]) a.push_back(pos[s1[i]]);
    // 对a做最长上升子序列
    for (int i = 0; i < a.size(); i++) {
        auto it = lower_bound(tails.begin(), tails.end(), a[i]);
        if (it == tails.end()) tails.push_back(a[i]);
        else *it = a[i];
    }
    cout << tails.size() << endl;
    return 0;
}