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

bool is_hw(int num) {
    string s = to_string(num);
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 100; i < 1000; i++) {
        if (isprime(i) && is_hw(i)) {
            cout << i << endl;
        }
    }
    return 0;
}