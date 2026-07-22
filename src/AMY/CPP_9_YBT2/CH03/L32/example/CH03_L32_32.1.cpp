//
// Created by Amy on 2026/7/11.
//
#include<bits/stdc++.h>
using namespace std;
double n, o = 2, cnt;
int main() {
    cin >> n;
    for (int i = 1 ; ; i++) {
        if (n <= 0) break;
        n -= o;
        o *= 0.98;
        cnt++;
    }
    cout << cnt;
    return 0;
}
