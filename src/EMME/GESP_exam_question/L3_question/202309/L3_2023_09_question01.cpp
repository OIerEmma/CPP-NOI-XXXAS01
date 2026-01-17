//
// Created by Emma on 2025/6/9.
//
#include<iostream>
using namespace std;

int a[1010];

int main() {
    int n, d, x;
    cin >> n >> d;
    for (int i = 1; i <= d; i++) {
        cin >> x;
        a[x] += i;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}