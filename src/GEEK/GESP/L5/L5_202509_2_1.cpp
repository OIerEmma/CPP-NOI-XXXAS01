//
// Created by Geek.Kwok on 2026/3/12.
//
#include <iostream>
using namespace std;

int l, r;
long long ans;

int countBits(int n) {
    int ans = 0;
    while (n) {
        if (n & 1) {
            ans++;
        }
        n >>= 1;
    }
    return ans;
}

bool isInteresting(int n) {
    return false;
}

long long count(int x) {
    return 0;
}

int main() {
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (countBits(i) % 2) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}