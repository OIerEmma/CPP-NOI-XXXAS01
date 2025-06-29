//
// Created by Emma on 2025/6/25.
//
#include<iostream>
using namespace std;

int a[100010];

int main() {
    int n, k;
    cin >> n >> k;
    int maxx = -100001, minn = 100001;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < k) {
            a[i] = minn;
        } else if (a[i] > k) {
            a[i] = maxx;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}