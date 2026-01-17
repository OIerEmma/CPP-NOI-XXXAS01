//
// Created by Emma on 2025/4/7.
//
#include<iostream>
using namespace std;
int a[100000],  r[100000];
long long ans = 0;

void msort(int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    msort(start, mid);
    msort(mid + 1, end);
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            r[k++] = a[i++];
        } else {
            r[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) {
        r[k++] = a[i++];
    }
    while (j <= end) {
        r[k++] = a[j++];
    }
    for (int num = start; num <= end; num++) {
        a[num] = r[num];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    msort(0, n - 1);
    printf("%lld\n", ans);
    return 0;
}
