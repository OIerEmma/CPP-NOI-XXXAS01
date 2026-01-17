//
// Created by Emma on 2025/7/3.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string a = s;
    for (int i = 0; i < s.size() - 1; i++) {
        s[i] = char(a[i] + a[i + 1]);
    }
    s[s.size() - 1] = char(a[a.size() - 1] + a[0]);
    cout << s << endl;
    return 0;
}