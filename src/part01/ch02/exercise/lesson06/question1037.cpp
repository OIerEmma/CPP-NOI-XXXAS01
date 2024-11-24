//
// Created by Emma on 2024/11/24.
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