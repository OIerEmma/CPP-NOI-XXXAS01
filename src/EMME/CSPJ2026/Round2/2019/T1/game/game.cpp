//
// Created by Emme.Kwok on 2026/9/24.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 8; i++)
        if (s[i] == '1') ans++;
    cout << ans << endl;
    return 0;
}