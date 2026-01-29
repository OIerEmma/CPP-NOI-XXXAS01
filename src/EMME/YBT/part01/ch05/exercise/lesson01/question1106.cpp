//
// Created by Emma on 2025/1/18.
//
#include<iostream>

int main() {
    double n = 0;
    double a[10] = {0}, age[101] = {0};
    double b[10] = {0};
    scanf("%lf", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &age[i]);
    }
    for (int i = 1; i <= n; i++) {
        if ((age[i] >= 0) && (age[i] <= 18))
            a[1]++;
        else if ((age[i] >= 19) && (age[i] <= 35))
            a[2]++;
        else if ((age[i] >= 36) && (age[i] <= 60))
            a[3]++;
        else if (age[i] >= 61)
            a[4]++;
        else continue;
    }
    for (int j = 1; j <= 4; j++) {
        b[j] = (a[j] / n) * 100;
    }
    for (int j = 1; j <= 4; j++) {
        printf("%.2lf%%\n", b[j]);
    }
    return 0;
}
