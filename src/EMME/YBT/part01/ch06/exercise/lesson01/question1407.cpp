//
// Created by Emma on 2025/2/23.
//
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int x) {
    if (x == 1 || x == 0) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int a[26];

int main() {
    char ch[100000];
    int max = 0, min = 9999;
    cin >> ch;
    size_t len = strlen(ch);

    for (int i = 0; i < int(len); i++) {
        a[ch[i] - 'a'] = a[ch[i] - 'a'] + 1;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min && a[i] != 0) {
            min = a[i];
        }
    }
    if (isprime(max - min)) {
        cout << "Lucky Word" << endl;
        cout << max - min << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}
