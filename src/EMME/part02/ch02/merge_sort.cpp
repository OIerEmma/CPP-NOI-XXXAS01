//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;
int a[101], r[101];

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
        }
    }
    while (i <= mid) {
        r[k++] = a[i++];
    }
    while (j <= end) {
        r[k++] = a[j++];
    }
    for (int x = start; x <= end; x++) {
        a[x] = r[x];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    msort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}