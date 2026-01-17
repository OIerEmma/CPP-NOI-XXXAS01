//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    int ans = 0, s;
    for (int i = 1; i <= 15; i++) {
        cin >> s;
        if (s == 100) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}