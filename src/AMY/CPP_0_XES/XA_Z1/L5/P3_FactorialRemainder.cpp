//
// Created by Emma on 2025/8/31.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, sum = 1;
    // cin >> n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum *= i;
        sum %= 10007;
    }
    cout << sum << endl;
    return 0;
}