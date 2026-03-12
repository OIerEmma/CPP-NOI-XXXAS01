//
// Created by Amy on 2026/3/8.
//
#include<iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        sum += i * i;
    }
    cout << sum;
    return 0;
}
