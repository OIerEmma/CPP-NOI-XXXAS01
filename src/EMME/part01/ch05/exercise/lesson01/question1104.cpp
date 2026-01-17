//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;

int main() {
    double b, a[20] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65}, sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> b;
        sum = sum + b * a[i];
    }
    cout << sum;
    return 0;
}
