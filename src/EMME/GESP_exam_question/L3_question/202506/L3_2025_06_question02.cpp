//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int a[1010];

int main() {
    int n, l = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        l = max(a[i], l + 1);
        ans += l;
    }
    cout << ans << endl;
    return 0;
}
/*
4
1 4 3 3
1:1
2:4
3:4 + 1 = 5
4:5 + 1 = 6
1 + 4 + 5 + 6 = 16
 */