//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
#include<map>
using namespace std;

map<char, int> m;

int main() {
    string s;
    cin >> s;
    int sc;
    cin >> sc;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
    }
    int ans = -1;
    for (auto p:m) {
        ans = max(ans, p.second);
    }
    cout << ans * sc << endl;
    return 0;
}