//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    n *= 1000;
    while (n > 0) {
        n -= 50 + 3000;
        ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}