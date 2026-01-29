//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    char t;
    cin >> s >> t;
    char *pt = &s[0];
    for (int i = 0; i < s.size(); i++) {
        if (*pt == t) {
            cout << i + 1 << endl;
            return 0;
        }
        pt++;
    }
    cout << "no" << endl;
    return 0;
}