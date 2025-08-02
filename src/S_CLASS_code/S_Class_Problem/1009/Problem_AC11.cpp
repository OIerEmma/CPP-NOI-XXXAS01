//
// Created by Emma on 2025/7/31.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int odd = 0, even = 0, num;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            if (num % 2 == 1) {
                odd++;
            } else {
                even++;
            }
        }
        if (even > odd) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}