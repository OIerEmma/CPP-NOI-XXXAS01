//
// Created by Emma on 2024/12/19.
//
#include<iostream>
using namespace std;

int main() {
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) {
        if(i % 2 == 0) {
            sum1 += i;
        } else {
            sum2 += i;
        }
    }
    cout << sum1 << " " << sum2;
    return 0;
}