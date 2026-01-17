//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i] - 48;
    }
    cout << ans << endl;
    return 0;
}