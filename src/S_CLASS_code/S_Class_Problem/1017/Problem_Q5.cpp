//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int a[310];

int main() {
    long long n, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        num += a[i];
    }
    cout << num << endl;
    return 0;
}