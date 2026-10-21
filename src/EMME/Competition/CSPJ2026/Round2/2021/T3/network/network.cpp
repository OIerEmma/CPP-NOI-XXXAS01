//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

bool check(string &s) {
    int p = (int)s.find(':');
    if (p == string::npos || s.find(':', p + 1) != string::npos) return false;
    string ip = s.substr(0, p), port = s.substr(p + 1);
    vector<string> v;
    string cur;
    for (char c : ip + ".") {
        if (c == '.') {
            if (cur.empty()) return false;
            v.push_back(cur);
            cur.clear();
        } else if (c >= '0' && c <= '9') cur += c;
        else return false;
    }
    if (v.size() != 4 || port.empty()) return false;
    for (auto x : v)
        if (x.size() > 1 && x[0] == '0' ||
            x.size() > 3 || stoi(x) > 255) return false;
    if (port.size() > 1 && port[0] == '0'
        || port.size() > 5) return false;
    for (char c : port) if (!isdigit(c)) return false;
    return stoi(port) <= 65535;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    string type, s;
    map<string, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> type >> s;
        if (!check(s)) { cout << "ERR\n"; continue; }
        if (type == "Server") {
            if (mp.count(s)) cout << "FAIL\n";
            else { mp[s] = i; cout << "OK\n"; }
        } else {
            if (mp.count(s)) cout << mp[s] << "\n";
            else cout << "FAIL\n";
        }
    }
    return 0;
}