//
// Created by Emme.Kwok on 2026/9/20.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("E_pingpong.in", "r", stdin);
    // freopen("E_pingpong.out", "e", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s, temp;
    // int n;
    // cin >> n;
    bool flag = false;
    // while (n--) {
    while (cin >> temp) {
        // cin >> temp;
        if (flag) continue;
        for (int i = 0; i < temp.size(); i++)
            if (temp[i] == 'E') {
                temp = temp.substr(0, i);
                flag = true;
                break;
            }
        s += temp;
    }
    // cout << s << endl;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        if (mp[s[i]] >= 11 && abs(mp['W'] - mp['L']) >= 2) {
            cout << mp['W'] << ":" << mp['L'] << "\n";
            mp['W'] = mp['L'] = 0;
        }
    }
    cout << mp['W'] << ":" << mp['L'] << "\n\n";
    mp['W'] = mp['L'] = 0;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        if (mp[s[i]] >= 21 && abs(mp['W'] - mp['L']) >= 2) {
            cout << mp['W'] << ":" << mp['L'] << "\n";
            mp['W'] = mp['L'] = 0;
        }
    }
    cout << mp['W'] << ":" << mp['L'] << "\n";
    return 0;
}
