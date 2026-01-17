//
// Created by Emme.Kwok on 2025/9/19.
//
#include<iostream>
using namespace std;

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (n > 200 || n < 0) {
        cout << "error" << endl;
    } else {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isprime(i)) {
                ans += i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}