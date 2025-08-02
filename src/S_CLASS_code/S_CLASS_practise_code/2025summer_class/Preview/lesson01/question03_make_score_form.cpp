//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

int a[110][110];
double r[110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    double t;
    int cnt = 1;
    for (int i = 1; i <= m; i++) {
        t = 0.0;
        for (int j = 1; j <= n; j++) {
            t += a[j][i];
        }
        r[cnt++] = round(t / n * 100);
        r[cnt - 1] /= 100;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d(%.2lf) ", a[i][j], r[j]);
        }
        cout << endl;
    }
    return 0;
}

/*
3 4
80 90 90 50
100 100 100 100
60 60 100 30
*/