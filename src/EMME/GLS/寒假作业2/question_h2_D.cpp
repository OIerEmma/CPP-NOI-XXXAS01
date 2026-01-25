//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    double n, a, b, c;
    cin >> n >> a >> b >> c;
    double ans = n - (a + b + c);
    cout << ans << endl;
    if (ans >= 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}