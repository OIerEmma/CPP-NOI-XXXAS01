//
// Created by Emme.Kwok on 2026/4/22.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 3e5 + 5;
vector<int> a(N), r(N);

long long msort(int start, int end) {
    if (start + 1 == end) return 0;
    int mid = (start + end) / 2;
    long long res = msort(start, mid) + msort(mid, end);
    for (int i = start, j = mid, k = start; k < end; k++) {
        if (j == end || a[i] > a[j] && i < mid) r[k] = a[i++];
        else r[k] = a[j++], res += mid - i;
    }
    for (int x = start; x < end; x++) a[x] = r[x];
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << msort(0, n) << endl;
    return 0;
}