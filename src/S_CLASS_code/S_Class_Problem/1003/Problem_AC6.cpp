//
// Created by Emma on 2025/7/3.
//
#include<iostream>
using namespace std;

int a[100010];

int main() {
    string s, t;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 97]++;
        if (a[s[i] - 97] == 1) {
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (a[s[i] - 97] == 1) {
            t += s[i];
        }
    }
    bool flag = false;
    if (!t.empty()) {
        for (int i = 0; i < s.size(); i++) {
            if (a[s[i] - 97] == 1) {
                for (int j = 0; j < t.size(); j++) {
                    if (t[j] == s[i]) {
                        cout << s[i] << endl;
                        flag = true;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
    } else {
        cout << "no" << endl;
    }
    return 0;
}