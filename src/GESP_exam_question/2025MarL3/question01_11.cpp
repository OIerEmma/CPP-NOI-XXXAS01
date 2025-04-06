//
// Created by Emma on 2025/3/30.
//
#include<iostream>
using namespace std;

int main() {
    int x;
    bool flag = false;
    scanf("%d", &x);
    for (int i = 1; i <= 2025; i++) {
        if ((x & i) + (x | i) == 2025) {
            printf("%d\n", i);
            flag = true;
            break;
        }
    }
    if (!flag) {
        printf("-1\n");
    }
    return 0;
}