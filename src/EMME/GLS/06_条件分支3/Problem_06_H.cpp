//
// Created by Emme.Kwok on 2026/3/14.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = n / 3 * 2, s = n % 3;
    if (s > 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}