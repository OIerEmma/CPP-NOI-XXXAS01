//
// Created by Emma on 2025/2/2.
//
#include<iostream>
using namespace std;

int main() {
    int n, num, maxvalue = -1, minvalue = 101, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num);
        maxvalue = max(num, maxvalue);
        minvalue = min(num, minvalue);
        sum += num;
    }
    sum -= maxvalue + minvalue;
    printf("%.2lf", sum * 1.0 / (n - 2));
    return 0;
}