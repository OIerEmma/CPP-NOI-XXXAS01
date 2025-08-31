//
// Created by Emma on 2025/8/9.
//
#include<iostream>
using namespace std;

int main() {
    long long ans = 0;
    string s;
    cin >> s;
    const int len = s.size();
    int pre_i = len; char pre_s = ' ';
    for (int i = len - 3; i >= 0; i--) {
        if (s[i] == s[i + 1] && s[i + 1] != s[i + 2]) {
            ans += len - i - 2;
            if (pre_s == s[i]) {
                ans -= len - pre_i;
            }
            for (int j = i + 3; j < pre_i; j++) {
                if (s[j] == s[i]) {
                    ans--;
                }
            }
            pre_i = i;
            pre_s = s[pre_i];
        }
    }
    cout << ans << endl;
    return 0;
}
