//
// Created by Emma on 2025/4/13.
//
#include<iostream>
#include<algorithm>
using namespace std;

string s[101];

int main() {
    string ss;
    int n = 0;
    while (cin >> ss) {
        s[++n] = ss;
    }
    for (int i = 1; i <= n - 1; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (s[i] != s[i - 1]) {
            cout << s[i] << endl;
        }
    }
    return 0;
}
