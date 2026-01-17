//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    long long k = 0, w = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 1) {
            k += a[i];
        } else {
            w *= a[i];
        }
    }
    cout << "KING " << k << endl;
    cout << "WIN " << w << endl;
    return 0;
}
