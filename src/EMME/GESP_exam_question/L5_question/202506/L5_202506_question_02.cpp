//
// Created by Emme.Kwok on 2026/3/11.
//
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int a[100005], b[505];
int main() {
    int n, q;
    cin >> n >> q;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i != 1 && a[i] != a[i - 1]) {
            flag = false;
        }
    }
    if (flag) {
        for (int i = 1; i <= q; i++) {
            // cout << a[1] + i << "\n";
            printf("%d\n", a[1] + i);
        }
        exit(0);
    }
    int temp = gcd(a[1], a[2]);
    for (int i = 3; i <= n; i++) {
        temp = gcd(temp, a[i]);
        if (temp == 1) {
            break;
        }
    }
    b[0] = temp;
    for (int i = 1; i <= q; i++) {
        if (temp != 1 && i % temp == 0) {
            // cout << temp << "\n";
            printf("%d\n", temp);
            continue;
        }
        if (temp != 1 && b[i % temp]) {
            // cout << b[i % temp] << "\n";
            printf("%d\n", b[i % temp]);
            continue;
        }
        int agcd = gcd(a[1] + i, a[2] + i);
        for (int j = 3; j <= n; j++) {
            agcd = gcd(agcd, a[j] + i);
            if (agcd == 1) {
                break;
            }
        }
        b[i % temp] = agcd;
        printf("%d\n", agcd);
    }
    return 0;
}