//
// Created by Emme.Kwok on 2026/3/10.
//
#include<iostream>
using namespace std;

int main() {
    int n, m, a, b, ans = -1;
    cin >> n >> m >> a >> b;
    int maxnm = max(n, m), minnm = min(n, m), maxab = max(a, b), minab = min(a, b);
    for (int i = 0; i <= minnm / minab; i++) {
        int j = (minnm - i * minab) / maxab;
        if (i * maxab + j * minab <= maxnm) {
            ans = max(ans, i + j);
        }
    }
    cout << ans << endl;
    return 0;
}