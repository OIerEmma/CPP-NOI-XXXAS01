//
// Created by Emma on 2024/11/19.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int i = 1;
    long j = 123;
    printf("%d,%2d,%03d,%ld,%-4ld,%05ld", i, i, i, j, j, j);
    return 0;
}