//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int a, b, gw, sw, bw, sum;
int main() {
    cin >> a >> b;
    sum = a + b;
    cout << sum << endl;
    gw = sum % 10,sum /= 10;
    sw = sum % 10,sum /= 10;
    bw = sum;
    if (a + b >= 100 && gw == bw || a + b >= 10 && a + b <= 99 && gw == sw || a + b >= 0 && a + b <= 9)
        cout << "Yes";
    else cout << "No";
    return 0;
}
