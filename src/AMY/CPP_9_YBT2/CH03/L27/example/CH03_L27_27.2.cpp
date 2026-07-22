//
// Created by Amy on 2026/6/30.
//
#include<bits/stdc++.h>
using namespace std;
int n, m;
double sum;
int main() {
    cin >> m;
    n = sum = 1;
    while(sum < m) {
        n++;
        sum += 1.0 / n;
    }
    cout << n;
    return 0;
}
