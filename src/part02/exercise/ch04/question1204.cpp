//
// Created by Emma on 2025/4/4.
//
#include<iostream>
using namespace std;

int floor(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return floor(n - 1) + floor(n - 2);
}

int main() {
    int n;
    while (cin >> n) {
        printf("%d\n", floor(n));
    }
    return 0;
}
