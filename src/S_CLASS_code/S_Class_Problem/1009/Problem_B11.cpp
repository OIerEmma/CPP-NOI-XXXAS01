//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

int main() {
    int a, d1, b, d2;
    cin >> a >> d1 >> b >> d2;
    int ans1 = 0, ans2 = 0;
    while (a) {
        if (a % 10 == d1) {
            ans1 = ans1 * 10 + d1;
        }
        a /= 10;
    }
    while (b) {
        if (b % 10 == d2) {
            ans2 = ans2 * 10 + d2;
        }
        b /= 10;
    }
    cout << ans1 + ans2 << endl;
    return 0;
}