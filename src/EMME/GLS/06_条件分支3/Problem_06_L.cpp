//
// Created by Emme.Kwok on 2026/3/14.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int d, maxab = max(a, b), minab = min(a, b);
    d = maxab - minab;
    int x = minab - d, z = maxab + d;
    cout << x << endl;
    if ((maxab - minab) % 2 == 0) {
        cout << minab + d / 2 << endl;
    }
    cout << z << endl;
    return 0;
}