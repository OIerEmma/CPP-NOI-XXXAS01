//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

int b[10001];

int main() {
    int n, num;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        b[num]++;
    }
    int maxx = 0, ans = 0;
    for (int i = 1; i <= 10000; i++) {
        if (maxx < b[i]) {
            maxx = max(maxx, b[i]);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
