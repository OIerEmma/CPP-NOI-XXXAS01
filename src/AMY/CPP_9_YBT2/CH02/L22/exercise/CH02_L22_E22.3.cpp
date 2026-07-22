//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int a, n, m;
int main() {
    cin >> a;
    n = a / 100;
    m = a % 100;
    if (n == m) {
        cout << "YES";
    }else {
        cout << "NO";
    }
    return 0;
}
