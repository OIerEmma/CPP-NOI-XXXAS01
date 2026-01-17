//
// Created by Emma on 2025/3/9.
//
#include<iostream>
using namespace std;

int main() {
    int n, d, whichbox;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < d; i++) {
        cin >> whichbox;
        a[whichbox] += i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}