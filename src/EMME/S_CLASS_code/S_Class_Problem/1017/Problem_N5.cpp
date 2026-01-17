//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = -1, num;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num % 2 == 0 && num > ans) {
            ans = num;
        }
    }
    cout << ans << endl;
    return 0;
}