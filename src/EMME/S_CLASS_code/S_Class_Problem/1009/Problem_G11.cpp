//
// Created by Emma on 2025/7/12.
//
#include<iostream>
using namespace std;

int to_int(string num) {
    int ans = 0, pos = 0;
    if (num[0] == '-') {
        pos = 1;
    }
    for (int i = pos; i < num.size(); i++) {
        ans = ans * 10 + int(num[i] - 48);
    }
    if (num[0] == '-') {
        ans = 0 - ans;
    }
    return ans;
}

string no_d(string s) {
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ',') {
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    string a, b;
    while (cin >> a && cin >> b) {
        cout << to_int(no_d(a)) + to_int(no_d(b)) << endl;
    }
    return 0;
}