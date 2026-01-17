//
// Created by Emma on 2025/6/25.
//
#include<iostream>
using namespace std;

int a[100010];

int main() {
    int n, k, maxx = -100001, minn = 100001;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > k) {
            a[i]= maxx;
        } else if (a[i] < k) {
            a[i] = minn;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}