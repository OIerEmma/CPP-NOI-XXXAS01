//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

typedef int (*LP)(int, int);

int main() {
    LP p = sum;
    cout << p(2, 5);
    return 0;
}
