//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

int main() {
    long long v, a, b, d = 0, ans = 0;
    cin >> a >> b >> v;
    while (d < v) {
        ans++;
        d += a;
        if (d >= v) {
            break;
        }
        d -= b;
    }
    cout << ans << endl;
    return 0;
}