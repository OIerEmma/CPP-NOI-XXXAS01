//
// Created by Amy on 2026/7/22.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    double xa, ya, xb, yb;
    cin >> xa >> ya;
    cin >> xb >> yb;
    double ans = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    cout << fixed << setprecision(3) << ans;
    return 0;
}