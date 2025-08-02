//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

bool isprime(int num) {
    if (num < 2) {
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
    for (int i = 2; i <= n - 2; i++) {
        if (isprime(i) && isprime(i + 2)) {
            cout << i << " " << i + 2 << endl;
        }
    }
    return 0;
}
