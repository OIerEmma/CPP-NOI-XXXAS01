//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    int ans = 0, num, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}