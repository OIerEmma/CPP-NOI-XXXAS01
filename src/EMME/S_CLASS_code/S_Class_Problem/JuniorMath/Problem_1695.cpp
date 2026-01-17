//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[15];

int main() {
    int t, n;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        cin >> n;
        int i;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool flag = false;
        sort(a + 1, a + n + 1);
        int s = a[1];
        for (i = 2; i <= n; i++) {
            if (a[i] > s) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << a[i] << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}