//
// Created by Emma on 2025/7/9.
//
#include<iostream>
using namespace std;

long long a[100];

int main() {
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    if (n <= 1) {
        cout << n << endl;
    } else {
        cout << a[n - 1] << endl;
    }
    return 0;
}