//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            ans -= c;
        } else {
            ans += c - 96;
        }
    }
    cout << ans << endl;
    return 0;
}