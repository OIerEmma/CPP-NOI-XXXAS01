//
// Created by Emma on 2025/7/4.
//
#include<iostream>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    char ch = s[0];
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (ch != s[i]) {
            ch = s[i];
            cnt = 0;
        }
        cnt++;
        if (cnt >= k) {
            cout << ch << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "No" << endl;
    }
    return 0;
}