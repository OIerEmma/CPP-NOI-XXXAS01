//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int *p;
int **pp;

int main() {
    int a = 10;
    p = &a;
    pp = &p;
    printf("%d=%d=%d\n", a, *p, **pp);
    return 0;
}
