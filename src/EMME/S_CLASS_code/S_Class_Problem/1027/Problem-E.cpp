//
// Created by Emma on 2025/1/15.
//
#include<iostream>
using namespace std;

int main() {
    int a1, a2, n, diff, ans;
    cin >> a1 >> a2 >> n;
    diff = a2 - a1;
    ans = a1 + (n-1) * diff;
    cout << ans << endl;
    return 0;
}