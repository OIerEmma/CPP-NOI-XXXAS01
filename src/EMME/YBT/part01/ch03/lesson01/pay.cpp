//
// Created by Emma on 2024/11/30.
//
#include<cstdio>
#include<iostream>
using namespace std;

int main() {
    float w, s;
    scanf("%f", &w);
    if(w <= 20) {
        s = 1.68 * w;
        printf("%.2f\n", s);
    } else {
        s = 1.98 * w;
        printf("%.2f\n", s);
    }
    return 0;
}