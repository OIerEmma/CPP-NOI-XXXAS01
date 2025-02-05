//
// Created by Emma on 2025/2/4.
//
#include<iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    printf("%d", max(a, max(b, c)));
    return 0;
}