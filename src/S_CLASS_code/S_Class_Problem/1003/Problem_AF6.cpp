//
// Created by Emma on 2025/7/3.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            ans += "T";
        } else if (s[i] == 'T') {
            ans += "A";
        } else if (s[i] == 'C') {
            ans += "G";
        } else {
            ans += "C";
        }
    }
    cout << ans << endl;
    return 0;
}