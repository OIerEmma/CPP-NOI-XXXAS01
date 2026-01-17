//
// Created by Emma on 2025/7/7.
//
#include<iostream>
using namespace std;

int nixu(int n) {
    int ans = 0;
    while(n != 0) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

bool real_prime(int n) {
    int m = nixu(n);
    if (n < 2 || m < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    bool flag = false;
    for (int i = m; i <= n; i++) {
        if (real_prime(i)) {
            if (!flag) {
                cout << i;
                flag = true;
            } else {
                cout << "," << i;
            }
        }
    }
    return 0;
}