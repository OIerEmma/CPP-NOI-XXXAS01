//
// Created by Emme.Kwok on 2026/9/27.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int v[N], a[N];

int main() {
    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, d, no;
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) cin >> a[i];
    cin >> no;
    long long ans = 0, fuel = 0;
    for (int i = 1, next; i < n; i += next) {
        next = 1;
        long long sum = 0;
        while (i + next < n && a[i + next] >= a[i]) sum += v[i + next - 1], next++;
        sum += v[i + next - 1];
        ans += 1LL * ((sum - fuel + d - 1) / d) * a[i];
        fuel = fuel + 1LL * (sum - fuel + d - 1) / d * d - sum;
        // cout << "ans:" << ans << "fuel:" << fuel << endl;
    }
    cout << ans << endl;
    return 0;
}