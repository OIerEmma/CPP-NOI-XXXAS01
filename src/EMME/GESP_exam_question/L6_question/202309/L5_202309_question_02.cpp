//
// Created by Emme.Kwok on 2026/4/22.
//
#include<iostream>
using namespace std;

int a[300010], r[300010], ans;

void msort(int start, int end) {
    if (start == end) return;
    int mid = (start + end) / 2;
    msort(start, mid);
    msort(mid + 1, end);
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (a[i] >= a[j]) r[k++] = a[i++];
        else r[k++] = a[j++];
    }
    while (i <= mid) r[k++] = a[i++];
    while (j <= end) r[k++] = a[j++];
    for (int x = start; x <= end; x++) a[x] = r[x];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    msort(1, n);
    cout << ans << endl;
    return 0;
}