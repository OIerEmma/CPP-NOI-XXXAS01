//
// Created by Emme.Kwok on 2026/2/26.
//
#include<iostream>
using namespace std;

bool isprime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (isprime(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}