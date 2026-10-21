//
// Created by Emme.Kwok on 2026/10/9.
//
#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;
int n, d, k, x[500005], s[500005], f[500005], q[500005];

bool check(int g) {
    long long lo = max(1, d - g), hi = d + g;
    x[0] = f[0] = 0;
    int head = 0, tail = 0, j = 0;
    for (int i = 1; i <= n; i++) {
        while (j < i && x[i] - x[j] >= lo) {
            if (f[j] != NEG) {
                while (head < tail && f[q[tail - 1]] <= f[j]) tail--;
                q[tail++] = j;
            }
            j++;
        }
        while (head < tail && x[i] - x[q[head]] > hi) head++;
        if (head < tail) f[i] = f[q[head]] + s[i];
        else f[i] = NEG;
        if (f[i] >= k) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> d >> k;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> s[i];
        if (s[i] > 0) sum += s[i];
    }
    if (sum < k) cout << "-1\n", exit(0);
    int l = 0, h = x[n];
    while (l < h) {
        int mid = (l + h) / 2;
        if (check(mid)) h = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}