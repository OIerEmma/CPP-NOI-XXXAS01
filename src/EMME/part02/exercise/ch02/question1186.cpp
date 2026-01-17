//
// Created by Emma on 2025/4/16.
//
#include<iostream>
#include<cstring>
using namespace std;

int number[100], shuzi[1000];

int main() {
    memset(number, 0, sizeof(number));
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &shuzi[i]);
        number[shuzi[i] + 50]++;
    }
    for (int i = 0; i < 100; i++) {
        if (number[i] > n / 2) {
            printf("%d\n", i - 50);
            flag = true;
        }
    }
    if (!flag) {
        printf("no\n");
    }
    return 0;
}
