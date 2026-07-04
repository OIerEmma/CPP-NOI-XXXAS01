//
// Created by Emme.Kwok on 2026/7/3.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int N = n;
    int a[N];
    int pre[N];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int x, y;
    cin >> x >> y;
    cout << pre[y] - pre[x - 1];
    return 0;
}