//
// Created by Amy on 2026/6/14.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 6) cout << 5 * n;
    else  cout << 5 * 6 + (n - 6) * 7;
    return 0;
}