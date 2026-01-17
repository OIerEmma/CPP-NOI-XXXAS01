//
// Created by Emma on 2025/2/10.
//
#include<iostream>
using namespace std;

int main() {
    int k, num = 1, num2 = 1, temp = 0;
    cin >> k;
    if (k == 1 || k == 2) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i <= k - 2; i ++) {
            temp = num + num2;
            num = num2;
            num2 = temp;
        }
        cout << temp << endl;
    }
    return 0;
}