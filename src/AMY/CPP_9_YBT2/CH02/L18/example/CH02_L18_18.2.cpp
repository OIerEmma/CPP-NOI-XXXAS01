//
// Created by Amy on 2026/6/14.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << "min=" << (a < b ? (a < c ? a : c) : (b < c ? b : c));
    return 0;
}