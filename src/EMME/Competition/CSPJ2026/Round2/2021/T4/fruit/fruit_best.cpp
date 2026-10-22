//
// Created by Emme.Kwok on 2026/10/21.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int t[N], pre[N], nxt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 0; i <= n + 1; i++) pre[i] = i - 1, nxt[i] = i + 1;
    t[0] = t[n + 1] = -1;
    vector<int> h;
    for (int i = 1; i <= n; i++)
        if (i == 1 || t[i] != t[i - 1]) h.push_back(i);
    while (!h.empty()) {
        vector<int> cand;
        for (int k = 0; k < h.size(); k++) {
            int s = h[k], r = nxt[s];
            cout << s << (k + 1 == h.size() ? "\n" : " ");
            nxt[pre[s]] = r;
            pre[r] = pre[s];
            if (t[r] == t[s]) cand.push_back(r);
        }
        h.clear();
        for (int c : cand) if (t[pre[c]] != t[c]) h.push_back(c);
    }
    return 0;
}