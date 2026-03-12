//
// Created by Emma on 2025/5/31.
//
#include<iostream>
using namespace std;

int sweet[30];

int main() {
    int n;
    scanf("%d", &n);
    sweet[0] = 1;
    sweet[1] = 1;
    for (int i = 2; i <= n; i++) {
        sweet[i] = sweet[i - 1] + sweet[i - 2];
    }
    printf("%d\n", sweet[n]);
    return 0;
}