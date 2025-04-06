//
// Created by Emma on 2025/3/12.
//
#include<iostream>
using namespace std;

bool condition1(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'
              || s[i] >= '0' && s[i] <= '9'
              || s[i] == '&' || s[i] == '@' || s[i] == '$' || s[i] == '!')) {
            return false;
        }
    }
    return true;
}

bool condition2(string s) {
    return s.size() >= 6 && s.size() <= 12;
}

bool condition3(string s) {
    bool upper_flag = false, lower_flag = false, digit_flag = false, special_flag = false;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            upper_flag = true;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            lower_flag = true;
        } else if (s[i] >= '0' && s[i] <= '9') {
            digit_flag = true;
        } else if (s[i] == '&' || s[i] == '@' || s[i] == '$' || s[i] == '!') {
            special_flag = true;
        }
    }
    return int(upper_flag + lower_flag + digit_flag) >= 2 && special_flag;
}

int main() {
    int len = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i ++) {
        if (str[i] == ',') {
            // 截取子串
            string sub = str.substr(i - len, len);
            // 条件判断
            if (condition1(sub) && condition2(sub) && condition3(sub)) {
                cout << sub << endl;
            }
            // 重置变量
            len = 0;
        } else {
            len ++;
        }
    }
    // 截取子串
    string sub = str.substr(str.size() - 1 - len, len);
    // 条件判断
    if (condition1(sub) && condition2(sub) && condition3(sub)) {
        cout << sub << endl;
    }
    return 0;
}