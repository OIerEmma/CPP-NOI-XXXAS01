//
// Created by Emma on 2024/12/25.
//
#include<iostream>
using namespace std;

int main() {
    int n, num, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> num;
        if (num % 10 - num / 1000 - num / 100 % 10 - num / 10 % 10 > 0) {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}