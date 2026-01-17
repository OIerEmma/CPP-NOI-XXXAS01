//
// Created by Emma on 2025/1/12.
//
#include<iostream>
using namespace std;
int MAXN = 10001;
int main() {
    int a[MAXN];
    int i, n, maxn, k;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    maxn = a [1];
    k = 1;
    for (i = 2; i <= n; i++) {
        if (a[i] > maxn) {
            maxn = a[i];
            k = i;
        }
    }
    cout << k << endl;
    return 0;
}