//
// Created by Geek.Kwok on 4/11/26.
//
#include <iostream>
using namespace std;

#define LL long long

bool flag[10005];

LL qpow(LL a, LL b, LL p) {
    LL res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    LL no = 0, last = no;
    for (int i = 1; i < n; i++) {
        int mod = n - i + 1;
        LL cnt = qpow(m, k + i, mod) % mod + mod;
        // cout << cnt << " ";
        while (cnt > 0) {
            if (!flag[no]) { cnt--; last = no; }
            no = (no + 1) % n;
        }
        // cout << last << endl;
        flag[last] = true;
        // if (no == 0) no += (n-1);
        // flag[(no - 1 + n) % n] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}