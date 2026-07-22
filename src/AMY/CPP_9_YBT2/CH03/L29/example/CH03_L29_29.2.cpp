//
// Created by Amy on 2026/7/7.
//
#include<bits/stdc++.h>
using namespace std;

int a, b, ans = 1;

int main() {
    cin >> a >> b;
    for (int i = 1; i <= b; i++) {
        ans *= a;
        ans %= 1000;
    }
    printf("%03d",ans);
    return 0;
}