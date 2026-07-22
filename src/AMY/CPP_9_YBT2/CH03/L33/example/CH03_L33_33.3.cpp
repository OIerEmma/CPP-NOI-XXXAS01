//
// Created by Amy on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1000; i >= 0; i--) {
        if (i % n != 0 && i % m != 0) {
            cout << i;
            return 0;
        }
    }
}