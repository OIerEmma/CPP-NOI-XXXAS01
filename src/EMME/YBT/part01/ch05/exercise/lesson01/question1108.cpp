//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;
int a[10001];
int b[10001];
int tot[10001];
long long int ans;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        tot[i] = a[i] * b[i];
    }
    for (int i = 1; i <= n; i++) {
        ans = tot[i] + ans;
    }
    cout << ans;
    return 0;
}
