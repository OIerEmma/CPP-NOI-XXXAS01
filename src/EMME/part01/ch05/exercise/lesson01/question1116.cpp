//
// Created by Emma on 2025/1/19.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n + 1];
    x[0] = 0;
    int temp = 1, max = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (x[i] == x[i - 1]) temp++;
        else temp = 1;
        if (temp > max) max = temp;
    }
    printf("%d", max);
    return 0;
}
