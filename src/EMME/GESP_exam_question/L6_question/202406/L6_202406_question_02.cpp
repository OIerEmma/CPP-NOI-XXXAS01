//
// Created by Emme.Kwok on 2026/6/21.
//
#include<iostream>
#include<vector>
using namespace std;

void dfs(int root, int turn, vector<int> &box, vector<int>& cl, const vector<int> ch[]) {
    turn += box[root];
    if (turn & 1) cl[root] = !cl[root]; // 奇数次
    for (int i : ch[root]) dfs(i, turn, box, cl, ch);
}

int main() {
    int n, p;
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    scanf("%d", &n);
    vector<int> ch[n + 1];
    for (int i = 1; i < n; i++) {
        scanf("%d", &p);
        ch[p].push_back(i + 1);
    }
    vector<int> cl(n + 1);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) cl[i + 1] = s[i] - '0';
    int q, r;
    scanf("%d", &q);
    vector<int> box(n + 1, 0);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &r);
        box[r]++;
    }
    dfs(1, 0, box, cl, ch);
    for (int i = 1; i <= n; i++) printf("%d", cl[i]);
    return 0;
}