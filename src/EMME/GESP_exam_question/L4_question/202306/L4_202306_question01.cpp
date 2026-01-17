//
// Created by Emme.Kwok on 2026/1/17.
//
#include<iostream>
using namespace std;

bool is_a_lucky_num(long long num) {
    long long newnum = 0;
    for (int i = 1; num != 0; i++) {
        if (i % 2 == 0) {
            newnum = newnum * 10 + num % 10;
            num /= 10;
            continue;
        }
        long long digit = num % 10 * 7;
        while (digit > 9) {
            long long sum = 0;
            while (digit != 0) {
                sum += digit % 10;
                digit /= 10;
            }
            digit = sum;
        }
        num /= 10;
        newnum = newnum * 10 + digit;
    }
    long long numsum = 0;
    while (newnum != 0) {
        numsum += newnum % 10;
        newnum /= 10;
    }
    return !(numsum % 8);
}

int main() {
    int n;
    cin >> n;
    long long x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (is_a_lucky_num(x)) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }
    return 0;
}