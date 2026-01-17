//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    n %= 26;
    for (int i = 1; i <= n; i++) {
        char t = s[0];
        s.erase(0, 1);
        s += t;
    }
    cout << s << endl;
    return 0;
}