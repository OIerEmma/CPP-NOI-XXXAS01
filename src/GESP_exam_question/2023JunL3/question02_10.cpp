//
// Created by Emma on 2025/3/12.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    int len = 0;
    bool flag = false, flag2 = false, flag3 = false, flag4 = false, flag5 = true;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        // 1.是否满足条件1
        // 条件1:
            // (1) s[i] >= "a" and <= "z"
            // (2) s[i] >= "A" and <= "Z"
            // (3) s[i] == "&" or "!" or "@" or "$"
            // (4) s[i] >= "0" and <= "9"
        // 2.是否满足条件2
            // (1) n.size() >= 6 and <= 12
        // 3.是否满足条件3
            // (1) 数字，大写字母，小写字母中二个
        if (s[i] == ',') {
            if (len >= 6 && len <= 12 && flag5 && flag4 && int(flag + flag2 + flag3) >= 2) {
                cout << s.substr(i - len, len) << endl;
            }
            flag = false, flag2 = false, flag3 = false, flag4 = false, flag5 = true, len = 0;
        } else {
            len++;
            if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'
                || s[i] >= '0' && s[i] <= '9'
                || s[i] == '&' || s[i] == '@' || s[i] == '$' || s[i] == '!')) {
                while (i < s.size() - 1 && s[++i] != ',') len++;
                i--;
                flag5 = false;
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                flag = true;
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                flag2 = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                flag3 = true;
            }
            if (s[i] == '&' || s[i] == '@' || s[i] == '$' || s[i] == '!') {
                flag4 = true;
            }
        }
    }
    if (len >= 6 && len <= 12 && flag5 && flag4 && int(flag + flag2 + flag3) >= 2) {
        cout << s.substr(s.size() - 1 - len, len) << endl;
    }
    return 0;
}