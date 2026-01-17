//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int a[20010];

int main() {
    double sum = 0;
    int n, maxn = -1, minn = 101;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
        sum += a[i];
    }
    sum -= maxn + minn;
    sum = sum / (n - 2);
    printf("%.1lf\n", sum);
    return 0;
}
