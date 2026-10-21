//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

void ch(string &s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
}

int main() {
    string t, s, line;
    cin >> t;
    ch(t);
    getchar();
    getline(cin, line);
    int ans = 0, pos = -1;
    for (int i = 0; i <= (int)line.size(); i++) {
        if (i == (int)line.size() || line[i] == ' ') {
            if (!s.empty()) {
                ch(s);
                if (s == t) {
                    ans++;
                    if (pos == -1) pos = i - (int)s.size();
                }
                s.clear();
            }
        } else {
            s += line[i];
        }
    }
    ch(s);
    if (s == t) {
        ans++;
        if (pos == -1) pos = (int)line.size() - 1 - s.size();
    }
    if (ans) cout << ans << " ";
    cout << pos << "\n";
    return 0;
}
/*
TO
  oT  To     tO     ooot too     TO      to    oto euyq    To
*/