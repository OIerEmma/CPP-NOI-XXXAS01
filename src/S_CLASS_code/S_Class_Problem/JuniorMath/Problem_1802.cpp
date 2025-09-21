//
// Created by Emme.Kwok on 2025/9/19.
//
#include<iostream>
using namespace std;

int sum(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i] - 48;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << s.size() << endl;
    cout << sum(s) << endl;
    return 0;
}