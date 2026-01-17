//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

bool one_zero(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            return false;
        }
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    for (long long m = 1; ; m++) {
        if (m * n > 2000000000) {
            cout << "No found" << endl;
            break;
        }
        if (one_zero(to_string(n * m))) {
            cout << m << endl;
            break;
        }
    }
    return 0;
}