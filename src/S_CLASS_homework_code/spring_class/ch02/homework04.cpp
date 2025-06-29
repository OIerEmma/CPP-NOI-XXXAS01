//
// Created by Emma on 2025/4/12.
//
#include<iostream>
using namespace std;
int a[5000000];

int main() {
    int n, k, m;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        m = i;
        for (int j = i; j < n; j++) {
            if (a[m] < a[j]) {
                m = j;
            }
        }
        if (m != i) {
            swap(a[i], a[m]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
