//
// Created by Emme.Kwok on 2025/9/20.
//
#include<iostream>
using namespace std;

int f(int n) {
    int ans = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) {
                ans++;
            } else {
                ans += 2;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << n - f(n) << endl;
    }
    return 0;
}