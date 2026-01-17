//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    long long n, num, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}