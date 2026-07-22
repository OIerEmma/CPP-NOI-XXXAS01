//
// Created by Emme.Kwok on 2026/7/21.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long pre1 = 0, pre2 = 0;
        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            long long v1, v2;
            if (i == 1) v1 = 0, v2 = x;
            else v1 = max(pre1, pre2), v2 = pre1 + x;
            pre1 = v1;
            pre2 = v2;
        }
        cout << max(pre1, pre2) << endl;
    }
    return 0;
}