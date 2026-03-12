//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int *a, int *b, int *c) {
    if (*a > *b) {
        swap(a, b);
    }
    if (*a > *c) {
        swap(a, c);
    }
    if (*b > *c) {
        swap(b, c);
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sort(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}
