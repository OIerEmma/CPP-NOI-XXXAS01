//
// Created by Emma on 2025/7/4.
//
#include<iostream>
using namespace std;

int ans[300];

int main() {
    string s;
    int len = 0, j = 0;
    getline(cin, s);
    s = s + " ";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ans[j++] = len;
            while(s[++i] == ' ');
            i--;
            len = 0;
        } else {
            len++;
        }
    }
    bool flag = false;
    for (int i = 0; i < j; i++) {
        if (flag) {
            cout << "," << ans[i];
        } else {
            cout << ans[i];
            flag = true;
        }
    }
    cout << endl;
    return 0;
}