//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

long long a[1010];

bool issquare(long long a) {
    return (long long)sqrt(a) * (long long)sqrt(a) == a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (issquare(a[i] + a[j])) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}