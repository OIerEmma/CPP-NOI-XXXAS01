//
// Created by Emma on 2024/12/21.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, num, maxValue = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        maxValue = max(num, maxValue);
    }
    cout << maxValue << endl;
    return 0;
}
