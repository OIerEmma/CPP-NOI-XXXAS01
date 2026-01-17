//
// Created by Emma on 2025/1/16.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    while (n != 0) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}