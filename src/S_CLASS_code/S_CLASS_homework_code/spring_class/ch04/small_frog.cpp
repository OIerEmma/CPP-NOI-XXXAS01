//
// Created by Emma on 2025/4/26.
//
#include<iostream>
using namespace std;

int a[1000001];

int main() {
    int n, index = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int index2 = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) {
                index2 = j;
            }
            if (a[j] == 0) {
                index = j;
            }
        }
        swap(a[index2], a[index]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
