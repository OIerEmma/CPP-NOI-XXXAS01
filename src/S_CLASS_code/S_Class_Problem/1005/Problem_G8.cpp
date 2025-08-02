//
// Created by Emma on 2025/7/9.
//
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int x[10010], y[10010];

int calc(int base, int *y, int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans += abs(y[i] - base);
    }
    return ans;
}

int main() {
    int n, y1, y2 = -10001;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(y, y + n);
    if (n % 2 == 0) {
        y1 = y[n/2 - 1], y2 = y[n/2];
    } else {
        y1 = y[n/2];
    }
    int min_res = calc(y1, y, n);
    if (y2 > -10001) {
        min_res = min(min_res, calc(y2, y, n));
    }
    cout << min_res << endl;
    return 0;
}
