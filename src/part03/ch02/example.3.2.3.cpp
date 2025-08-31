//
// Created by Emma on 2025/8/28.
//
#include<iostream>
using namespace std;

int a[100001];

int main() {
    int n, m;
    cin >> n >> m;
    int j = n, k = 1, p = 0;
    for (int i = 1; i < n; i++) {
        a[i] = i + 1;
    }
    a[n] = 1;
    while (p < n) {
        while (k < m) {
            j = a[j];
            k++;
        }
        cout << a[j] << " ";
        p++;
        a[j] = a[a[j]];
        k = 1;
    }
    return 0;
}