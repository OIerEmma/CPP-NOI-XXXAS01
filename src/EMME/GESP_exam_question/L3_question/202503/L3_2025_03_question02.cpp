//
// Created by Emma on 2025/6/27.
//
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> m;

string s_to_lower(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = (char)tolower(s[i]);
    }
    return s;
}

int main() {
    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        s = s_to_lower(s);
        m[s]++;
    }
    int ans = -1;
    string res;
    for (auto p:m) {
        if (ans < p.second) {
            ans = p.second;
            res = p.first;
        }
    }
    cout << res << endl;
    return 0;
}
