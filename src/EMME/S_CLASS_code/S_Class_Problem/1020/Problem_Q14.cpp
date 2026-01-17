//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int main() {
    int n, num, maxx = 0, minn = 101, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        ans += num;
        maxx = max(maxx, num);
        minn = min(minn, num);
    }
    ans -= maxx + minn;
    printf("%.1lf", ans * 1.0 / (n - 2));
    return 0;
}