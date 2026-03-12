//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 9;
char c[maxn][maxn];

int main() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    bool allBlackFlag = true;
    for (int i = 1; i <= 8; i++) {
        bool flag = false;
        for (int j = 1; j <= 8; j++) {
            if (c[i][j] != 'B') {
                allBlackFlag = false;
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans++;
        }
    }
    for (int i = 1; i <= 8; i++) {
        bool flag = false;
        for (int j = 1; j <= 8; j++) {
            if (c[j][i] != 'B') {
                allBlackFlag = false;
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans++;
        }
    }
    if (allBlackFlag) {
        ans -= 8;
    }
    cout << ans << endl;
    return 0;
}