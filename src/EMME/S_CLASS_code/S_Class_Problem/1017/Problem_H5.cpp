//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    int ans = 0, angle;
    for (int i = 1; i <= 10; i++) {
        cin >> angle;
        if (angle == 90) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}