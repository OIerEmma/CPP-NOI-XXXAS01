//
// Created by Emme.Kwok on 2026/2/3.
//
#include<iostream>
#include<cstdio>
using namespace std;

bool flag[13];

bool A(string s) {
    if (s[0] == 'A') {
        flag[0] = true;
        return true;
    }
    return false;
}

bool C(string s) {
    int c = 0, idx = 0;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C') {
            c++;
            idx = i;
        }
    }
    if (c == 1) {
        flag[idx] = true;
        return true;
    }
    return false;
}

bool l_l(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (!(flag[i] || s[i] >= 'a' && s[i] <= 'z')) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    string s;
    cin >> s;
    if (A(s) && C(s) && l_l(s)) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    return 0;
}