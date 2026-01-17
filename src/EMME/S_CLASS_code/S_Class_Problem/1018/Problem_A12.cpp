//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int s = 0, ans = 0;
    while (s < x) {
        s += y;
        s--;
        ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}