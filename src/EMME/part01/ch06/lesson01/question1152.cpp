//
// Created by Emma on 2025/2/22.
//
#include<iostream>
using namespace std;

double m_value(double a, double b, double c) {
    const double ans1 = max(a + b, max(b, c));
    const double ans2 = max(a, max(b, b + c));
    const double ans3 = max(a, max(b, c));
    return ans3 / (ans1 * ans2);
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.3lf\n", m_value(a, b, c));
    return 0;
}