//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s << " ";
    for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}