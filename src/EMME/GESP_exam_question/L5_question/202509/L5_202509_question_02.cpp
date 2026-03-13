//
// Created by Emme.Kwok on 2026/2/26.
//
#include<iostream>
using namespace std;

long long l, r, b;
long long ans = 0;
const int v[9] = {0, 1, 3, 3, 7, 7, 7, 14, 22};

int check(long long num) {
    int cnt = 0;
    while(num) {
        if (num & 1) {
            cnt++;
        }
        num >>= 1;
    }
    return cnt;
}

long long work(long long n) {
    if (n <= 8) {
        return v[n];
    }
    b = n >> 2;
    ans = (b * b << 2) - b;
    for (long long i = b << 2; i <= n; i++) {
        if (check(i) % 2) {
            ans += i;
        }
    }
    return ans;
}

int main() {
    cin >> l >> r;
    cout << work(r) - work(l - 1) << endl;
    return 0;
}