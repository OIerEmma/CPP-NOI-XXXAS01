//
// Created by Emma on 2025/3/14.
//
#include<iostream>
using namespace std;
long long h[1001];

void dfs(const long long m) {
    if (h[m] != -1) {
        return;
    }
    h[m] = 1;
    for (int i = 1; i <= m / 2; i++) {
        dfs(i);
        h[m] += h[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        h[i] = -1;
    }
    dfs(n);
    printf("%lld\n", h[n]);
    return 0;
}