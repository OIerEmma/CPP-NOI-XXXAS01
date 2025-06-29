//
// Created by Emma on 2025/6/9.
//
#include<iostream>
using namespace std;

int a[1024];

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int num;
    for (int i = 0; i < d; i++) {
        scanf("%d", &num);
        a[num] += i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}