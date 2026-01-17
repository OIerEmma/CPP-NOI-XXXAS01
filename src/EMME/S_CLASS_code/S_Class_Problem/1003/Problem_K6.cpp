//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    int zro = 0, nen = 0, tix = 0, sne = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] <= 18) {
            zro++;
        } else if (a[i] >= 19 && a[i] <= 35) {
            nen++;
        } else if (a[i] >= 36 && a[i] <= 60) {
            tix++;
        } else {
            sne++;
        }
    }
    printf("%d %.2lf%%\n", zro, zro * 1.0 / n * 100);
    printf("%d %.2lf%%\n", nen, nen * 1.0 / n * 100);
    printf("%d %.2lf%%\n", tix, tix * 1.0 / n * 100);
    printf("%d %.2lf%%\n", sne, sne * 1.0 / n * 100);
    return 0;
}