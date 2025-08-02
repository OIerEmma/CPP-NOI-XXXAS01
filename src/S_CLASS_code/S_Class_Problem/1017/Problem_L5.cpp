//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    int m, n, ans = 0;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        ans += i;
    }
    cout << ans << endl;
    return 0;
}