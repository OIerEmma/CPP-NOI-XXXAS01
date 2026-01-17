//
// Created by Emma on 2025/3/8.
//
#include<iostream>
using namespace std;

string reverse(string s) {
    if (s.length() == 1) {
        return s;
    }
    char a = s[s.length() - 1];
    string b = s.substr(0, s.length() - 1);
    return a + reverse(b);
}

int main() {
    string str;
    cin >> str;
    str = str.erase(str.size() - 1, 1);
    cout << reverse(str);
    return 0;
}
