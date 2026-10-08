//
// Created by Geek.Kwok on 2026/10/3.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
int lc[N], rc[N], val[N], nodeCnt, varNode[N];
char op[N];
bool sens[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<int> init(n + 1);
    for (int i = 1; i <= n; i++) cin >> init[i];
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        int u;
        if (c == 'x') {
            int id = 0;
            while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9')
                id = id * 10 + s[++i] - '0';
            u = ++nodeCnt;
            op[u] = 'x';
            val[u] = init[id];
            varNode[id] = u;
            st.push(u);
        } else if (c == '!') {
            int a = st.top(); st.pop();
            u = ++nodeCnt;
            op[u] = '!'; lc[u] = a;
            val[u] = !val[a];
            st.push(u);
        } else if (c == '&' || c == '|') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            u = ++nodeCnt;
            op[u] = c; lc[u] = a; rc[u] = b;
            val[u] = (c == '&' ? val[a] & val[b] : val[a] | val[b]);
            st.push(u);
        }
    }
    int root = st.top();
    sens[root] = true;
    for (int i = nodeCnt; i >= 1; i--) {
        if (!sens[i] || op[i] == 'x') continue;
        if (op[i] == '!') sens[lc[i]] = true;
        else if (op[i] == '&') {
            if (val[rc[i]] == 1) sens[lc[i]] = true;
            if (val[lc[i]] == 1) sens[rc[i]] = true;
        } else {
            if (val[rc[i]] == 0) sens[lc[i]] = true;
            if (val[lc[i]] == 0) sens[rc[i]] = true;
        }
    }
    int q, i;
    cin >> q;
    while (q--) {
        cin >> i;
        cout << (sens[varNode[i]] ? !val[root] : val[root]) << "\n";
    }
    return 0;
}