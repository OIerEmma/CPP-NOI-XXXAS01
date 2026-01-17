//
// Created by Emma on 2025/2/14.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    unsigned int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] + a[j] == int(sqrt(a[i] + a[j])) * int(sqrt(a[i] + a[j]))) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
