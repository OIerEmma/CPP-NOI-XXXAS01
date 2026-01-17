//
// Created by Emma on 2024/11/18.
//
#include<cstdio>
#include<iostream>
using namespace std;

int main() {
    //example 1
    int a, b;
    scanf("%d %*d %d", &a, &b);
    printf("a=%d b=%d\n", a, b);

    //example 2
    int a2, b2;
    scanf("%4d%4d", &a2, &b2);
    printf("a=%d,b=%d\n",a2, b2);

    //exaple 3
    char st[40];
    memset(st, '\0', sizeof(st));
    scanf("%s", st);
    printf("%s\n", st);

    //example 4
    int a3, b3, c;
    scanf("%d,%d,%d", &a3, &b3, &c);
    printf("a3=%d,b3=%d,c=%d\n", a3, b3, c);
    return 0;
}
