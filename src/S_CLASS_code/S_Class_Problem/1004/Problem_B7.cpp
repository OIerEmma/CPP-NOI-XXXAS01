//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

bool isprime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int b[110];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        b[s[i] - 97]++;
    }
    int maxn = -1, minn = 101;
    for (int i = 0; i < 26; i++) {
        maxn = max(maxn, b[i]);
        if (b[i] != 0 && minn > b[i]) {
            minn = b[i];
        }
    }
    if (isprime(maxn - minn)) {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}