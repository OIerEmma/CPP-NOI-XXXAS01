//
// Created by Emma on 2025/7/3.
//
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = s;
    for (int i = int(s.size() - 1); i >= 0; i--) {
        ans[s.size() - 1 - i] = s[i];
    }
    for (int i = 0; i < s.size(); i++) {
        ans[i] = char(ans[i] + 3);
        if (!(ans[i] >= 'a' && ans[i] <= 'z' ||
            ans[i] >= 'A' && ans[i] <= 'Z')) {
            ans[i] -= 26;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (ans[i] >= 'a' && ans[i] <= 'z') {
            ans[i] = char(ans[i] - 32);
        } else {
            ans[i] = char(ans[i] + 32);
        }
    }
    cout << ans << endl;
    return 0;
}

