//
// Created by Emma on 2025/2/20.
//
#include <iostream>
using namespace std;

bool is_perfect_number(int num) {
    if (num <= 1) {
        return false;
    }
    int sum = 1;
    for (int j = 2; j * j <= num; ++j) {
        if (num % j == 0) {
            sum += j;
            if (j * j != num) {
                sum += num / j;
            }
        }
    }
    if (sum == num) {
        return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        if (is_perfect_number(i)) {
            cout << i << endl;
        }
    }
    return 0;
}