//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int n, num, sum_a = 0, sum_b = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if(num >= 0) {
            sum_a += num;
        } else {
            sum_b += num;
        }
    }
    printf("%d", sum_a - sum_b);
    return 0;
}