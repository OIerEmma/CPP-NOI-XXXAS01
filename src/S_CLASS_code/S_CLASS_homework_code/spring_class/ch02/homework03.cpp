//
// Created by Emma on 2025/4/12.
//
#include<iostream>
using namespace std;
int a[5000];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    int ans = abs(a[1] - a[0]);
    for (int i = 1; i < n - 1; i++) {
        if (ans < abs(a[i] - a[i + 1])) {
            ans = abs(a[i] - a[i + 1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
