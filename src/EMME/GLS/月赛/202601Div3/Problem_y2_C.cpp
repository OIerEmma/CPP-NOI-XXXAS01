//
// Created by Emme.Kwok on 2026/1/27.
//
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
    freopen("abc.in", "r", stdin);
    freopen("abc.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag = false;
        for (int a = 2; a <= (int)pow(n, 1.0 / 3); a++) {
            for (int b = a + 1; b <= (int)sqrt(n / 2); b++) {
                if (n % (a * b) == 0) {
                    int c = n / (a * b);
                    if (c > b) {
                        flag = true;
                        cout << a << " " << b << " " << c << endl;
                        break;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
        }
    }
    return 0;
}