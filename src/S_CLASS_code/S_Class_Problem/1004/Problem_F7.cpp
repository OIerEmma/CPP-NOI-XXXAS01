//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
    return 0;
}