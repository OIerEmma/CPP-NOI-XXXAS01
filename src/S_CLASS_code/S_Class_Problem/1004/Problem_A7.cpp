//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = int(s.size() - 1); i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}