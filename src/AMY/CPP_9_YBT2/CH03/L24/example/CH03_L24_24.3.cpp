//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int n, m, sum;
int main() {
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (i % 2) sum += i;
    }
    cout << sum;
    return 0;
}
