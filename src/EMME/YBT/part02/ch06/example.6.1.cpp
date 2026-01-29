//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 1005;
int a[maxn], idx[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swap(idx[j], idx[j + 1]);
            }
        }
    }
    int minn = 0;
    // int j = 0;
    // for (int i = 1; i < n; i++) {
    //     j += a[i];
    //     minn += j;
    // }
    for (int i = 1; i <= n; i++) {
        minn += a[i] * (n - i);
    }
    for (int i = 1; i <= n; i++) {
        cout << idx[i] << " ";
    }
    printf("\n%.2lf\n", minn * 1.0 / n);
    return 0;
}
/*
3 2 7 8 1 4 9 6 10 5
291.90
 */