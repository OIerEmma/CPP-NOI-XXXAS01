//
// Created by Emma on 2024/12/19.
//
#include<iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}