//
// Created by Emme.Kwok on 2026/3/17.
//
#include<iostream>
using namespace std;

string word[25];
int n, vis[25], res = -1;

bool check(int j, string prev, string nword) {
    return prev.length() >= j && nword.substr(0, j) == prev.substr(prev.length() - j);
}

void dfs(string prev) {
    res = max(res, (int)prev.length());
    // cout << res << " " << prev << endl;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 2) continue;
        for (int j = 1; j <= word[i].length(); j++) {
            if (check(j, prev, word[i])) {
                string ss = prev + word[i].substr(j);
                if (ss == prev) continue;
                vis[i]++;
                dfs(ss);
                vis[i]--;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> word[i];
    }
    string dragon_head;
    cin >> dragon_head;
    dfs(dragon_head);
    cout << res << endl;
    return 0;
}