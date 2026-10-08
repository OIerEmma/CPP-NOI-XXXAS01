//
// Created by Geek.Kwok on 2026/9/20.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_pingpong.in", "r", stdin);
    // freopen("g_pingpong.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    string score;
    vector<string> s11, s21;
    int win11 = 0, lose11 = 0, win21 = 0, lose21 = 0;
    while (cin >> score) {
        bool end = false;
        for (auto c: score) {
            if (c == 'E') {
                end = true; break;
            }
            if (c == 'W') { win11++; win21++; }
            else if (c == 'L') { lose11++; lose21++; }
            // cout 11
            if ((win11 >= 11 || lose11 >= 11) && abs(win11 - lose11) >= 2) {
                s11.push_back(to_string(win11) + ":" + to_string(lose11));
                win11 = 0, lose11 = 0;
            }
            // cout 21
            if ((win21 >= 21 || lose21 >= 21) && abs(win21 - lose21) >= 2) {
                s21.push_back(to_string(win21) + ":" + to_string(lose21));
                win21 = 0, lose21 = 0;
            }
        }
        if (end) break;
    }

    s11.push_back(to_string(win11) + ":" + to_string(lose11));
    s21.push_back(to_string(win21) + ":" + to_string(lose21));

    for (auto s1: s11) cout << s1 << endl;
    cout << endl;
    for (auto s2: s21) cout << s2 << endl;
    return 0;
}