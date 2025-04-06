//
// Created by Emma on 2025/1/23.
//
#include<iostream>
using namespace std;

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int a, b;
    cin >> a >> b;
    swap(a, b);
    printf("%d %d\n", a, b);
    return 0;
}
