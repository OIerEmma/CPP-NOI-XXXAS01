//
// Created by Emme.Kwok on 2026/2/2.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100005;
long long m[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> m[i];
        }
        sort(m + 1, m + n + 1);
        // for (int i = 1; i <= n; i++) {
        //     cout << m[i] << " ";
        // }
        long long ans = 0, cnt = 0, remain = n;
        long long mina = m[1], minb = m[2], maxB = m[n], left = 0;
        for (int i = 1, j = n - 1; i + 1 < j; ) {
            if (cnt % 2 == 0) {
                ans += minb;
                ans += mina;
                left = minb;
                minb = m[i + 2];
                remain--;
            } else {
                ans += maxB;
                if (remain > 0) {
                    ans += left;
                    minb = left;
                }
                remain--;
                j -= 2;
                maxB = m[j + 1];
            }
            cnt++;
            // cout << "remain: " << remain << " ans: " << ans << endl;
        }

        if (remain == 3) {
            ans += (mina + minb + maxB);
        } else if (remain == 2) {
            ans += max(mina, minb);
        }
        cout << ans << endl;
    }
    return 0;
}