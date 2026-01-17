//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    long long people, n, sum = 0, num;
    cin >> people >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum += num;
    }
    sum *= people;
    cout << sum << endl;
    return 0;
}