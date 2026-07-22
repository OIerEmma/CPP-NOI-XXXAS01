//
// Created by Amy on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;
int n, flag;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) flag++;
    }
    if (flag == 2) {
        cout << "Y";
    }else {
        cout << "N";
    }
    return 0;
}
