//
// Created by Emma on 2025/1/15.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}