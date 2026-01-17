//
// Created by Emme.Kwok on 2026/1/10.
//
#include<iostream>
using namespace std;

const int maxn = 20;
int n, in[maxn], a[maxn], res;

bool isprime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int step) {
    if (step == n + 1) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                ans += in[i];
            }
        }
        if (isprime(ans)) {
            res++;
        }
        return;
    }
    for (int i = 1; i >= 0; i--) {
        a[step] = i;
        dfs(step + 1);
        a[step] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
    }
    dfs(1);
    cout << res;
    return 0;
}