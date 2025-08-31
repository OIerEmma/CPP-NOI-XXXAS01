//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

bool c(string s, int m) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    if (ans % m == 0) {
        return true;
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    for (int i = 10000; i <= 30000; i++) {
        string s = to_string(i);
        string str1 = s.substr(0, 3);
        string str2 = s.substr(1, 3);
        string str3 = s.substr(2, 3);
        if (c(str1, k) && c(str2, k) && c(str3, k)) {
            cout << i << endl;
        }
    }
    return 0;
}