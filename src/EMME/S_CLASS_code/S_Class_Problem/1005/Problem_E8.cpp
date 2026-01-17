//
// Created by Emma on 2025/7/8.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[200010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            ans++;
        } else {
            cout << a[i] << " " << ans << endl;
            ans = 1;
        }
    }
    return 0;
}