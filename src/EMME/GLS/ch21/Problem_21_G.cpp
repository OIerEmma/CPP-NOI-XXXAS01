//
// Created by Emme.Kwok on 2026/10/23.
//
#include<bits/stdc++.h>
using namespace std;

int mp[150];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    mp['a'] = 1;
    for (int i = 1; i <= n; i++) {
        char a, b, e;
        cin >> a >> e >> b;
        if (mp[a] && mp[b] == 0) mp[a] = 0;
        else if (mp[b] == 1) mp[a] = mp[b] = 1;
        // cout << mp[a] << " " << mp[b] << endl;
    }
    bool flag = true;
    // for (int i = 'a'; i <= 'z'; i++) cout << mp[i] << " ";
    // cout << endl;
    for (int i = 'a'; i <= 'z'; i++)
        if (mp[i]) {
            flag = false;
            cout << char(i) << " ";
        }
    if (flag) cout << "none\n";
    return 0;
}
/*
5
b=a
a=c
c=a
d=c
b=d
*/