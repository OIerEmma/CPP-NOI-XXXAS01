//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[500001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = -1;
    for (int i = 1; i < n; i++) {
        int num = 1;
        while (a[i] == a[i + 1]) {
            num++;
            i++;
        }
        ans = max(ans, num);
    }
    if (ans == -1) {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}