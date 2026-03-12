//
// Created by Emma on 2025/1/1.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        cout << n % 10 << " ";
        n /= 10;
    }
    return 0;
}