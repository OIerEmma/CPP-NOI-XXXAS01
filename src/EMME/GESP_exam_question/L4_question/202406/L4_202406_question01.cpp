//
// Created by Emme.Kwok on 2026/2/23.
//
#include<iostream>
using namespace std;

const int maxn = 15;
int a[maxn][maxn];

int main() {
    int n, m;
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    int black = 0, white = 0;
                    for (int p = i; p <= k; p++) {
                        for (int q = j; q <= l; q++) {
                            if (a[p][q] == 0) {
                                white++;
                            } else {
                                black++;
                            }
                        }
                    }
                    if (black == white) {
                        ans = max(ans, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}