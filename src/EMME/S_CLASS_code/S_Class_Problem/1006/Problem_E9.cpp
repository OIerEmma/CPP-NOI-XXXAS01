//
// Created by Emma on 2025/7/9.
//
#include<iostream>
using namespace std;

long long a[100010];

int main() {
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    cout << a[n] << endl;
    return 0;
}