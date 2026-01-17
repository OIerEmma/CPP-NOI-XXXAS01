//
// Created by Emma on 2025/7/30.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        for (int i = int(s.size() - 1); i >= 0; i--) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}