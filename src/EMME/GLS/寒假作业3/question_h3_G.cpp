//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = abs(a - b) / 10;
    if (abs(a - b) % 10 != 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}