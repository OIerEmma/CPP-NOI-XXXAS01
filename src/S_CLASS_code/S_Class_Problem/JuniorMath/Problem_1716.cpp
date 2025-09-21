//
// Created by Emme.Kwok on 2025/9/20.
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (isprime(i)) {
            cout << i << endl;
        }
    }
    return 0;
}