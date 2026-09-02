//
// Created by Emme.Kwok on 2026/8/29.
//
#include<bits/stdc++.h>
using namespace std;

bool isprime[100005];
int prime[100005];

int main() {
    int n;
    cin >> n;
    int ans = 0;
    memset(isprime, true, sizeof isprime);
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) ans++, prime[ans] = i;
        for (int j = 2; i * j <= n; j++) isprime[i * j] = false;
    }
    cout << ans << "\n";
    for (int i = 1; i <= ans; i++) cout << prime[i] << " ";
    return 0;
}