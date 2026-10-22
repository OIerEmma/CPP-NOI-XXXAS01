//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> s;

void dfs(int step, int no, const string& str) {
    if (step >= m) {
        if (no == 1) s.insert(str);
        return;
    }
    // 右边 no + 1
    if (no + 1 > n) dfs(step + 1, 1, str + "|" + to_string(no));
    else dfs(step + 1, no + 1, str + "|" + to_string(no));
    // 左边 no - 1
    if (no - 1 < 1) dfs(step + 1, n, str + "|" + to_string(no));
    else dfs(step + 1, no - 1, str + "|" + to_string(no));
}

int main() {
    cin >> n >> m;
    dfs(0, 1, "");
    cout << s.size() << endl;
    return 0;
}