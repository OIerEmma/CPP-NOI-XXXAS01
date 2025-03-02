//
// Created by Emma on 2025/2/22.
//
#include<iostream>
using namespace std;

bool isprime(int a) {
    if (a == 1) {
        return false;
    }
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 100; i < 1000; i++) {
        if (isprime(i) && i / 100 == i % 10) {
            printf("%d\n", i);
        }
    }
}
