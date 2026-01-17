//
// Created by Emma on 2024/12/29.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, ans = 1;
    cin >> a >> b;
    for (int i = 1; i <= b; i++) {
        ans *= a;
        ans %= 1000;
    }
    if (ans <= 10) {
        cout << "00" << ans << endl;
    } else if (ans <= 100) {
        cout << "0" << ans << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}