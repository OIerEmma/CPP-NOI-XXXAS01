//
// Created by Amy on 2026/3/17.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, t;
    cin >> a >> b;
    cout << "a=" << a << " " << "b=" << b << endl;
    t = a;
    a = b;
    b = t;
    cout << "a=" << a << " " << "b=" << b;
    return 0;
}
