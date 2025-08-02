//
// Created by Emma on 2025/4/12.
//
#include<iostream>
#include<algorithm>
using namespace std;
int a[100];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    int Alice = 0, Bob = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            Alice += a[i];
        } else {
            Bob += a[i];
        }
    }
    printf("%d\n", Alice - Bob);
    return 0;
}
