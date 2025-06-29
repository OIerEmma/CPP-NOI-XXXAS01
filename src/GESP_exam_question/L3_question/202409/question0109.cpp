//
// Created by Emma on 2025/6/24.
//
#include<iostream>
using namespace std;

int a[10010];

int main() {
    int t, n;
    cin >> t;
    for (int x = 1; x <= t; x++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt1, cnt2;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < i; j++) {
                cnt1 += a[j];
            }
            for (int j = i; j < n; j++) {
                cnt2 += a[j];
            }
            cout << cnt1 << " " << cnt2 << endl;
            if (cnt1 == cnt2) {
                cout << "Yes" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "No" << endl;
        }
    }
    return 0;
}