//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

bool isprime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; j <= i / 2; j++) {
            if (isprime(j) && isprime(i - j)) {
                cout << i << "=" << j << "+" << i - j << endl;
            }
        }
    }
    return 0;
}