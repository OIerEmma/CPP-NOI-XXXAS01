//
// Created by Emma on 2025/3/6.
//
#include<iostream>
using namespace std;

int change_unit(string s) {
    if (s[0] == 'k') {
        return 1000000;
    } else if (s.length() == 1) {
        return 1000;
    }
    return 1;
}

int main() {
    int n, x;
    string s1, s2, equal, question;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> s1 >> equal >> question >> s2;
        cout << x << " " << s1 << " " << equal << " " << change_unit(s1) / change_unit(s2) * x << " " << s2 << endl;
    }
    return 0;
}