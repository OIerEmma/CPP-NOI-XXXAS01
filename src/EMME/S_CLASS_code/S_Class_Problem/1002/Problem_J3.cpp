//
// Created by Emma on 2025/2/7.
//
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a, i, j, max;
    cin >> a;
    for (i = 2; i < sqrt(a); i++) {
        if (a % i == 0) {
            j = a / i;
            break;
        }
    }
    if (i > j) {
        max = i;
    } else {
        max = j;
    }
    cout << max;
}