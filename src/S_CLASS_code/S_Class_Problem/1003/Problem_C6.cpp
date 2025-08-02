//
// Created by Emma on 2025/6/30.
//
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag = true;
    s.erase(s.size() - 1, 1);
    for (int i = 0, j = int(s.size() - 1); i <= j; i++, j--) {
        if (s[i] != s[j]) {
            cout << "FALSE" << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "TRUE" << endl;
    }
    return 0;
}