//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}