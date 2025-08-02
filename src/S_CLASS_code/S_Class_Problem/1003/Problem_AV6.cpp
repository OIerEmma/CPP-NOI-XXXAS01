//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'z') {
            cout << "a";
        } else if (s[i] == 'Z') {
            cout << "A";
        } else if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
            cout << char(int(s[i]) + 1);
        } else {
            cout << s[i];
        }
    }
    return 0;
}