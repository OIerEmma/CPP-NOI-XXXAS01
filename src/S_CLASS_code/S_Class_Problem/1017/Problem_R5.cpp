//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

double a[110];

int main() {
    double ming, n;
    cin >> ming >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << ming << " ";
    for (int i = 1; i <= n; i++) {
        printf("%.2lf ", ming + a[i]);
    }
    return 0;
}
