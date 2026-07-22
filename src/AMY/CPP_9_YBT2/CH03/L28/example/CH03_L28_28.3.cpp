//
// Created by Amy on 2026/7/1.
//
#include<bits/stdc++.h>
using namespace std;
int n, m, a, sum, cnt;
int main() {
    cin >> n >> m;
    double e = 1, jc = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (sum + a > m) {
            cnt++;
            sum = a;
        }
        else sum += a;
    }
    cout << cnt + 1;
    return 0;
}
