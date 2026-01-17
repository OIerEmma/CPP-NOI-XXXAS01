//
// Created by Emma on 2024/11/23.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    double s_all = 6 * 9.6;
    double s_high = 5 * 9.4;
    double s_low = 5 * 9.8;
    double high = s_all - s_high;
    double low = s_all - s_low;
    double ans = (s_all - high - low) / 4;
    printf("%5.2f\n", ans);
    return 0;
}