//
// Created by Emma on 2024/12/28.
//
#include<iostream>
using namespace std;

int main() {
    int n, a = 0, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        a += 1;
        ans += a;
    }
    cout << ans - 1 << endl;
    return 0;
}