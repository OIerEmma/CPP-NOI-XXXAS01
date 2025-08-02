//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

bool c(string s) {
    // condition1
    if (s[0] >= '0' && s[0] <= '9') {
        return false;
    }
    // condition2
    if (s == "int" || s == "double" || s == "cout" || s == "cin") {
        return false;
    }
    for (int i = 0; i < s.size(); i++) {
        // cnodition3
        if (s[i] == ' ') {
            return false;
        }
        // condition4
        if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z'
            || s[i] >= '0' && s[i] <= '9' || s[i] == '_')) {
            return false;
        }
    }
    return true;
}


int main() {
    string s;
    getline(cin, s);
    if (c(s)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}