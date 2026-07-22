//
// Created by Amy on 2026/7/19.
//
#include<bits/stdc++.h>
using namespace std;

char c;

int main() {
    cin >> c;
    if (isupper(c)) cout << c - 0;
        else cout << char(c - 32);
    return 0;
}