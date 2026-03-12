//
// Created by Emme.Kwok on 2026/1/29.
//
#include<iostream>
using namespace std;

const int maxn = 103;
int a[maxn][maxn], sumr[maxn][maxn], sum[maxn][maxn];

int main() {
    int n;
    cin >> n;
    int ans = -128;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            ans = max(a[i][j], ans);
            sumr[i][j] = sumr[i][j - 1] + a[i][j];
            sum[i][j] = sumr[i][j] + sum[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i + 1; k <= n; k++) {
                for (int l = j + 1; l <= n; l++) {
                    ans = max(ans, sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
4
 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2
 */
