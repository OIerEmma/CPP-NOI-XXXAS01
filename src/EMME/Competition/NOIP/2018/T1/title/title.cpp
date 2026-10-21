//
// Created by Emme.Kwok on 2026/10/11.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ans = 0;
    for (char i : s)
        if (i == ' ') ans++;
    cout << s.size() - ans << endl;
    return 0;
}