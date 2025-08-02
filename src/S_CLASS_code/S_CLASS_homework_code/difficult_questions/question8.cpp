//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    int a, b, total = 0, badminton = 0, pinpong = 0, basketball = 0;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d\n", &a, &b);
        total += a;
        if(b == 0) {
            badminton += a;
        } else if(b == 1) {
            pinpong += a;
        } else {
            basketball += a;
        }
    }
    printf("%d\n", total);
    printf("%d %d %d\n", badminton, pinpong, basketball);
    printf("%.2lf%% %.2lf%% %.2lf%%",
        badminton * 1.0 / total * 100.0,
        pinpong * 1.0 / total * 100.0,
        basketball * 1.0 / total * 100.0);

    return 0;
}