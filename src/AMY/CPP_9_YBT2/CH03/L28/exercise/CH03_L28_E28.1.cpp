//
// Created by Amy on 2026/7/1.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a[n - 1], sum;
    cin >> n;
    sum = (n - 2) * 180;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        sum = sum - a[i];
    }
    cout << sum;
    return 0;
}