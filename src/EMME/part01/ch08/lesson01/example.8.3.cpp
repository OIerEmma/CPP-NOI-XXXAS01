//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int a = 10;
    double b = 3.5;
    void *p = &a;
    printf("%d\n", *(int *) p);
    p = &b;
    printf("%.1lf\n", *(double *) p);
    return 0;
}
