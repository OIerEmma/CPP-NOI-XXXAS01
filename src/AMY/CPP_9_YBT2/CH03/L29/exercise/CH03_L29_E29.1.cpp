#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    double ans = x;
    for (int i = 0; i < n; ++i) {
        ans *= 1.001;
    }
    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}