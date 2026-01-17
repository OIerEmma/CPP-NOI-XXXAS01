//
// Created by Emma on 2025/3/14.
//
#include<iostream>
using namespace std;

long long solve(const int n, const int k) {
    if (n < k || k == 0) {
        return 0;
    }
    if (n == k || k == 1) {
        return 1;
    }
    return solve(n - 1, k - 1) + solve(n - 1, k) * k;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}
