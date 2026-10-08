//
// Created by Emme.Kwok on 2026/9/28.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
struct node {
    int id, t;
} a[N];
long long pre[N];

bool cmp(node x, node y) {
    return x.t < y.t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].t, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].t;
    for (int i = 1; i <= n; i++) cout << a[i].id << " ", sum += pre[i - 1];
    cout << "\n";
    cout << fixed << setprecision(2) << sum * 1.0 / n << endl;
    return 0;
}