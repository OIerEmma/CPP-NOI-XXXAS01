//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int a[10010], pre[10010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (pre[i] == pre[n] - pre[i]) {
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