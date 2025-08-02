//
// Created by Emma on 2025/7/31.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0, j = int(s.size() - 1); i < j; i++, j--) {
        if (s[i] != s[j]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}