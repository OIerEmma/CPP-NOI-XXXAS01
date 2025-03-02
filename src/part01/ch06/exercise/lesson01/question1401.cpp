//
// Created by Emma on 2025/2/23.
//
#include<iostream>
using namespace std;

int a[1001] = {0}, ans = 0, m, n, x;
void replace();

int main() {
    int i;
    cin >> m >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        if (a[x] == 0 && ans < m) {
            ans++;
            a[x] = ans;
        } else;
        replace();
    }
    cout << ans << endl;
    return 0;
}

void replace() {
    int sum, i;
    if (a[x] == 0 && ans >= m) {
        ans++;
        sum = 0;
        for (i = 0; i <= 1000; i++) {
            if (a[i] >= 1) {
                a[i] = a[i] - 1;
                sum++;
            }
            if (sum == m) {
                break;
            }
        }
        if (m > 0) {
            a[x] = m;
        }
    }
}
