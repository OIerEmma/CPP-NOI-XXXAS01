//
// Created by Emma on 2025/3/8.
//
#include<iomanip>
#include<iostream>
using namespace std;

double hermite(int n, int x) {
    if (n == 0) {
        return 1;
    } else if(n == 1) {
        return 2 * x;
    }
    return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

int main() {
    int n, x;
    cin >> n >> x;
    cout << setprecision(2) << fixed << hermite(n, x) << endl;
    return 0;
}
