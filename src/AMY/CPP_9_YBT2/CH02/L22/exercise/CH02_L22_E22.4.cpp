//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        cout << "yes";
    }else {
        cout << "no";
    }
    return 0;
}
