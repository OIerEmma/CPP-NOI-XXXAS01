//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}