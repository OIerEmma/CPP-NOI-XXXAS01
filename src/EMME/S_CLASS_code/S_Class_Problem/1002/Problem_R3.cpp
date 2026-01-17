//
// Created by Emma on 2025/2/8.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int k, num, one = 0, five = 0, ten = 0;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> num;
        if (num == 1) {
            one++;
        } else if (num == 5) {
            five++;
        }
        if (num == 10) {
            ten++;
        }
    }
    cout << one << endl << five << endl << ten << endl;
    return 0;
}
