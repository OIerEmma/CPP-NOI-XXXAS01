//
// Created by Emma on 2025/7/4.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char now = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == now) {
            cnt++;
        } else {
            cout << cnt << now;
            now = s[i];
            cnt = 1;
        }
    }
    cout << cnt << now << endl;
    return 0;
}