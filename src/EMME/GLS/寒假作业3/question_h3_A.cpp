//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string s1 = s.substr(0, s.size() - 1);
    reverse(s1.begin(), s1.end());
    cout << s << s1;
    return 0;
}