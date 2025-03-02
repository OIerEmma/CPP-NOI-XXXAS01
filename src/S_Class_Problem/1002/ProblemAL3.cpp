//
// Created by Emma on 2025/2/20.
//
//
// Created by Emma on 2025/1/11.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n, num = 0;
    cin >> n;
    for (int i = 2, j; ; i++) {
        for (j = 2; j <= (int) sqrt(i); j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j > (int) sqrt(i)) {
            num ++;
        }
        if (num == n) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
