//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    long long k = 0, w = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            k += a[i];
        } else {
            w += a[i];
        }
    }
    if (k == w) {
        cout << "GOOD" << endl;
    } else if (k > w) {
        cout << "KING" << endl;
    } else {
        cout << "WIN" << endl;
    }
    return 0;
}
