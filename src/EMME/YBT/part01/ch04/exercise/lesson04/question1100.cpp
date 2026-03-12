//
// Created by Emma on 2025/1/11.
//
#include<iostream>
using namespace std;

int main() {
    int k, sum = 0, c = 1, q = 1;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        sum += c;
        q--;
        if (q == 0) {
            c++;
            q = c;
        }
    }
    cout << sum << endl;
    return 0;
}