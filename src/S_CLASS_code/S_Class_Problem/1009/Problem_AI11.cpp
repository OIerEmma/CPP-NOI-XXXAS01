//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if (a + b > c) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
    }
    return 0;
}