//
// Created by Emma on 2025/7/9.
//
#include<iostream>
using namespace std;

int a[30010];

int main() {
    int n, k, b, maxx = -1, minn = 30001;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        maxx = max(maxx, b);
        minn = min(minn, b);
        a[b]++;
    }
    for (int t = 0, i = minn; i <= maxx; i++) {
        if (a[i] != 0) {
            t++;
        }
        if (t == k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << "No result" << endl;
    return 0;
}
