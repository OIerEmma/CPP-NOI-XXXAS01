//
// Created by Emme.Kwok on 2026/3/8.
//
#include<iostream>
using namespace std;

#define ll long long
const int N = 1e5 + 10;
ll calc(ll x) {
    int ans = 0;
    ll tmp = 1;
    while (x >= tmp) {
        ans++;
        x -= tmp;
        tmp++;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ans += calc(cnt);
        }
    }
    if (n != 1) {
        ans += calc(1);
    }
    cout << ans << endl;
    return 0;
}