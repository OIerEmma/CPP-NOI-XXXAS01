//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = int(s.size() - 1); i >= 0; i--) {
        cout << s[i] << " ";
    }
    return 0;
}