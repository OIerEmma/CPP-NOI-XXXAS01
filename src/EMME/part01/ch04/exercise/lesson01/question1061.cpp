//
// Created by Emma on 2024/12/20.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, num, sum = 0;
    double average;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> num;
        sum += num;
    }
    average = sum * 1.0 / n;
    cout << sum << " ";
    printf("%.5lf", average);
    return 0;
}