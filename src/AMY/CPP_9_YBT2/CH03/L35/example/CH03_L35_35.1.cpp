//
// Created by Amy on 2026/7/14.
//
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    while (n > 0) {
        cout << n % 10 << " ";
        n = n / 10;
    }
    return 0;
}