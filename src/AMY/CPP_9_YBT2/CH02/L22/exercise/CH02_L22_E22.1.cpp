//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int a;
int main() {
    cin >> a;
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
        cout << a << "是闰年";
    }else {
        cout << a << "是平年";
    }
    return 0;
}
