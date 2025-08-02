//
// Created by Emma on 2025/6/30.
//
#include<iostream>
using namespace std;

int a[10];

int main() {
    int t;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cin >> t;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (t + 30 >= a[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}