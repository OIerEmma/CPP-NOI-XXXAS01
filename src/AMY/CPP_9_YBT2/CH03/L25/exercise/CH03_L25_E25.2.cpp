//
// Created by Amy on 2026/6/26
//
#include<bits/stdc++.h>
using namespace std;
int n, t, sum;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        sum += t;
    }
    cout << sum;
    return 0;
}
