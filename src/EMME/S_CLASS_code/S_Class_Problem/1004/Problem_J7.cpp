//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

bool isprime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int nixu(int num) {
    int ans = num % 10 * 10 + num / 10;
    return ans;
}

int main() {
    for (int i = 10; i <= 99; i++) {
        if (isprime(i) && isprime(nixu(i))) {
            cout << i << endl;
        }
    }
    return 0;
}