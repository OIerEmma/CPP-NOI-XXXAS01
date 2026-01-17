//
// Created by Emma on 2025/7/3.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}