//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int a[10010];

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i; j < n; j++) if (a[j] < a[k]) k = j;
        if (k != i) swap(a[i], a[k]);
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}