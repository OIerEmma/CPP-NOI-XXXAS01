//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int n, t;
long long sum;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t % 2 == 0)
            sum += t;
    }
    cout << sum;
    return 0;
}
