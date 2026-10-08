//
// Created by Emme.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

struct node { long long st, p; };

int main() {
    int n;
    cin >> n;
    long long ans = 0, type, np, nst;
    vector<node> s;
    for (int i = 1; i <= n; i++) {
        cin >> type >> np >> nst;
        if (!type) {
            ans += np;
            s.push_back({nst, np});
        } else {
            bool flag = false;
            for (int j = 0; j < s.size(); j++) {
                node x = s[j];
                if (nst - x.st <= 45 && x.p >= np) {
                    flag = true;
                    s.erase(s.begin() + j);
                    break;
                }
            }
            if (!flag) ans += np;
        }
    }
    cout << ans << endl;
    return 0;
}