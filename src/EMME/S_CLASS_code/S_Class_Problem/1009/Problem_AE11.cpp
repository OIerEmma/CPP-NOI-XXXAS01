//
// Created by Emma on 2025/7/31.
//
#include<iostream>
using namespace std;

string a[110];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i <= 4) {
            cout << "1=" << a[i];
            for (int j = i - 1, k = 2; j >= 1; j--) {
                cout << " " << k++ << "=" << a[j];
            }
        } else {
            cout << "1=" << a[i];
            for (int j = 1, k = 2; j < 4; j++) {
                cout << " " << k++ << "=" << a[i - j];
            }
        }
        cout << endl;
    }
    return 0;
}