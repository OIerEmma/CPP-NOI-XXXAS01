//
// Created by Emme.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int n, ans = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        ans += isprime(i);
    cout << ans << endl;
    return 0;
}