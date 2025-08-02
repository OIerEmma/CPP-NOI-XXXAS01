//
// Created by Emma on 2025/6/30.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    return 0;
}