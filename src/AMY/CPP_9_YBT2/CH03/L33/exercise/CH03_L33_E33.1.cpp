//
// Created by Amy on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1; i <= 200; i++) {
        if (i % 3 == 2 && i % 7 == 1) cout << i << " ";
    }
    return 0;
}