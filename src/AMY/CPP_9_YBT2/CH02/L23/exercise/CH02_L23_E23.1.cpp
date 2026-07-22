//
// Created by Amy on 2026/6/23.
//
#include<bits/stdc++.h>
using namespace std;
int x;
int main() {
    cin >> x;
    if (x >= 90) cout << "A";
    else if (x >= 70) cout << "B";
    else if (x >= 60) cout << "C";
    else cout << "D";
    return 0;
}