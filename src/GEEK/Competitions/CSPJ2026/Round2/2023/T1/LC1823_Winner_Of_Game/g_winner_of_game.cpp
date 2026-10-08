//
// Created by Geek.Kwok on 2026/9/21.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_winner_of_game.in", "r", stdin);
    // freopen("g_winner_of_game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    vector<bool> j(110, false);
    int n, m, pos = 0, cnt = 0;
    cin >> n >> m;
    while (cnt < n) {
        int c = 0;
        while (c < m) {
            pos = pos == n ? 1 : (pos + 1) % (n + 1);
            if (!j[pos]) c++;
        }
        j[pos] = true; cnt++;
        // cout << pos << " ";
    }
    cout << pos << endl;
    return 0;
}

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> j(n + 10, false);
        int pos = 0, cnt = 0;
        while (cnt < n) {
            int c = 0;
            while (c < k) {
                pos = pos == n ? 1 : (pos + 1) % (n + 1);
                if (!j[pos]) c++;
            }
            j[pos] = true; cnt++;
            // cout << pos << " ";
        }
        return pos;
    }
};