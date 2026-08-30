//
// Created by Emme.Kwok on 2026/8/28.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long L, F, W, na, nf;
    cin >> L >> F >> W >> na >> nf;
    vector<int> ca(na), aa(na), cf(nf), ff(nf);
    for (int i = 0; i < na; i++) cin >> ca[i] >> aa[i];
    for (int i = 0; i < nf; i++) cin >> cf[i] >> ff[i];
    vector<long long> dpa(W + 1, 0), dpf(W + 1, 0);
    for (int i = 0; i < na; i++)
        for (int c = W; c >= ca[i]; c--)
            dpa[c] = max(dpa[c], dpa[c - ca[i]] + aa[i]);
    for (int i = 0; i < nf; i++)
        for (int c = W; c >= cf[i]; c--)
            dpf[c] = max(dpf[c], dpf[c - cf[i]] + ff[i]);
    for (int c = 1; c <= W; c++) {
        dpa[c] = max(dpa[c], dpa[c - 1]);
        dpf[c] = max(dpf[c], dpf[c - 1]);
    }
    long long ans = L * F;
    for (int k = 0; k <= W; k++)
        ans = max(ans, (L + dpa[k]) * (F + dpf[W - k]));
    cout << ans << endl;
    return 0;
}