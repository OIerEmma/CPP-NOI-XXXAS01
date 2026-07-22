//
// Created by Amy on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;
int a, b;
int main() {
    for (int i = 1000; i <= 9999; i++) {
        a = i % 100;
        b = i / 100;
        if ((a + b) * (a + b) == i) cout << i << " ";
    }
    return 0;
}