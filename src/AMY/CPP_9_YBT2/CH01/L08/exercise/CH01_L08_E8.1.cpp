//
// Created by Amy on 2026/4/8.
//
#include<bits/stdc++.h>
using namespace std;
int r, n, m;
int main() {
    cin >> r;
    n = r % 10;
    m = r / 10;
    if(n != 0) {
        cout << n;
    }
    cout << m;
    return 0;
}
