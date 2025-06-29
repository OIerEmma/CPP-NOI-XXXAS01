//
// Created by Emma on 2025/4/12.
//
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];

bool cmp(int x, int y) {
    if (x % 10 == y % 10) {
        return x > y;
    }
    return x % 10 < y % 10;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
