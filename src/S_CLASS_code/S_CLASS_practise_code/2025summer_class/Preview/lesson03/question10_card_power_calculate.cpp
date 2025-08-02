//
// Created by Emma on 2025/7/12.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        int no;
        cin >> no;
        cout << 0 << endl;
    } else {
        int ans = 0;
        cin >> a[1];
        cout << 0 << endl;
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            sort(a + 1, a + i + 1);
            for (int j = 1; j < i; j++) {
                if (a[j] == a[j + 1]) {
                    ans += k;
                } else {
                    ans += abs(a[j] - a[j + 1]) * abs(a[j] - a[j + 1]);
                }
            }
            if (i == 2) {
                if (a[1] == a[2]) {
                    cout << k << endl;
                } else {
                    cout << abs(a[1] - a[2]) * abs(a[1] - a[2]) << endl;
                }
            } else {
                cout << ans << endl;
            }
            ans = 0;
        }
    }
    return 0;
}

/*
5 3
4
1
3
3
1
*/