//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        int ans = 0;
        for (int j = 2; j <= int(n/2); j++) {
            if (n % j == 0) {
                ans += (int)(n / j) - 1;
            }
        }
        cout << n - ans - 1 << endl;
    }
    return 0;
}
