//
// Created by Geek.Kwok on 2026/1/3.
//
#include<iostream>
using  namespace std;

bool b[9] = {0}, c[17] = {0}, d[17] = {0};
int a[9], sum;

void dfs(int i) {
    if (i == 9) {
        sum++;
        cout << "No. " << sum << endl;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <=  8; j++)
                if (a[j] == i) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
            cout << endl;
        }
        return;
    }
    for (int j = 1; j <= 8; j++) {
        if (!b[j] && !c[i + j] && !d[i - j + 7]) {
            a[i] = j;
            b[j] = 1;
            c[i + j] = 1;
            d[i - j + 7] = 1;
            dfs(i + 1);
            a[i] = 0;
            b[j] = 0;
            c[i + j] = 0;
            d[i - j + 7] = 0;
        }
    }
}

int main() {
    dfs(1);
    return 0;
}