//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int s;
    cin >> s;
    for (int i = s / 2; i < s - 1; i++) {
        if (isprime(i) && isprime(s - i)) {
            cout << i * (s - i) << endl;
            break;
        }
    }
    return 0;
}