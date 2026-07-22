//
// Created by Amy on 2026/7/14.
//
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    for ( ;n > 1; ) {
        if (n % 2 == 0) {
            cout << n << "/2=" << n / 2 << endl;
            n /= 2;
        }
        else {
            cout << n << "*3+1=" << n * 3 + 1 << endl;
            n *= 3;
            n++;
        }
    }
    cout << "End";
    return 0;
}