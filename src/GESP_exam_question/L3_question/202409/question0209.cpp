//
// Created by Emma on 2025/6/24.
//
#include<iostream>
using namespace std;

bool f(string s) {
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int x = 1; x <= n; x++) {
        cin >> s;
        bool flag = false;
        for (int i = 2; i < s.size() - 1; i++) {
            cout << s.substr(0, i) << endl << s.substr(i, s.size() - i) << endl;
            if (f(s.substr(0, i)) && f(s.substr(i, s.size() - i))) {
                cout << "Yes" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "No" << endl;
        }
    }
    return 0;
}