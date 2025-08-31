//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[20];
char x[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
    for (int i = 1; i <= 17; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    sum += a[1] * 7 + a[2] * 9 + a[3] * 10 + a[4] * 5 + a[5] * 8 + a[6] * 4 + a[7] * 2 + a[8] + a[9] * 6;
    sum += a[10] * 3 + a[11] * 7 + a[12] * 9 + a[13] * 10 + a[14] * 5 + a[15] * 8 + a[16] * 4 + a[17] * 2;
    int mod = (int)sum % 11;
    cout << x[mod] << endl;
    return 0;
}