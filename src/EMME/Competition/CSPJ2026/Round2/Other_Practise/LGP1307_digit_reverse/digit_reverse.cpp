//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] == '-') cout << "-", s.erase(0, 1);
    reverse(s.begin(), s.end());
    while (s[0] == '0' && s.size() > 1) s.erase(0, 1);
    cout << s << endl;
    return 0;
}