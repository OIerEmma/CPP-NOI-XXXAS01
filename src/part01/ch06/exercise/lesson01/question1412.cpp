//
// Created by Emma on 2025/3/2.
//
#include<iostream>
using namespace std;

bool TwoData(int x) {
    int a = 0, b = 0;
    while (x > 0) {
        if (x % 2 == 1)
            a++;
        else
            b++;
        x /= 2;
    }
    return a > b;
}

int main() {
    int a = 0, b = 0;
    for (int i = 1; i <= 1000; i++) {
        if (TwoData(i)) {
            a++;
        }
        else {
            b++;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}

