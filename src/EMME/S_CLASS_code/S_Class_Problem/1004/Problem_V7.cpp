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
    int n, m;
    cin >> m >> n;
    bool flag = false;
    for (int i = m; i <= n; i++) {
        for (int j = i; j >= 2; j--) {
            if (i % j == 0 && isprime(j)) {
                if (flag) {
                    cout << "," << j;
                } else {
                    cout << j;
                    flag = true;
                }
                break;
            }
        }
    }
    return 0;
}