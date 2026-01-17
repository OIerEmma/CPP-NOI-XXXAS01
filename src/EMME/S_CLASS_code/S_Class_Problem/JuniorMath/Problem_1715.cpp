//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

long long fac(int n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans += fac(i);
    }
    cout << ans << endl;
    return 0;
}