//
// Created by Emme.Kwok on 2025/9/12.
//
#include<iostream>
using namespace std;

int a[80010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + 1;
        while (a[j] <= a[i] && j <= n) {
            ans++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}