#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL qpow(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans % p;
}

bool flag[10005];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int now = 0;
    for (int i = 1; i < n; i++) {
        LL cnt = qpow(m, k + i, n) % n;
        cout << cnt << " ";
        while (cnt >= 0) {
            if (!flag[now % n]) cnt--;
            now++;
        }
        flag[now - 1] = true;
        cout << now - 1 << endl;
    }
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}