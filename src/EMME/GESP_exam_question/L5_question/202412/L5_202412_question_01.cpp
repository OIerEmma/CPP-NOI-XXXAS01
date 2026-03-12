//
// Created by Emme.Kwok on 2026/3/1.
//
#include<iostream>
using namespace std;

long long ans;

void calc(long long cnt) {
    long long tmp = 1;
    while (cnt >= tmp) {
        ans++;
        cnt -= tmp;
        tmp++;
    }
}

// 质因数分解
void fj(long long x) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            calc(cnt);
        }
    }
    if (x != 1) {
        calc(1);
    }
}

int main() {
    long long n;
    cin >> n;
    fj(n);
    cout << ans << endl;
    return 0;
}