//
// Created by Emme.Kwok on 2026/9/21.
//
#include<bits/stdc++.h>
using namespace std;

int id[100005];
string name[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, s, pos = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> id[i] >> name[i];
    for (int i = 1; i <= m; i++) {
        cin >> a >> s;
        if (id[pos] == a) pos -= s;
        else pos += s;
        if (pos <= 0) pos += n;
        else if (pos > n) pos -= n;
    }
    cout << name[pos] << endl;
    return 0;
}
