//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[11];

int main() {
    int t;
    for (int i = 1; i <= 10; i++) {
        cin >> a[i];
    }
    cin >> t;
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        if (t + 30 >= a[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}