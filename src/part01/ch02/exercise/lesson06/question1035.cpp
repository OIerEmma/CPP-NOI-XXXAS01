//
// Created by Emma on 2024/11/24.
//
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    int a1, a2, n, diff, ans;
    cin >> a1 >> a2 >> n;
    diff = a2 - a1;
    ans = a1 + (n-1) * diff;
    cout << ans << endl;
    return 0;
}