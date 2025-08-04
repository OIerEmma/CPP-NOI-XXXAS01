//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    long long sum = 0, num;
    for (; ;) {
        cin >> num;
        if (num == 0) {
            break;
        }
        if (num < 0) {
            sum += num;
        }
    }
    cout << sum << endl;
    return 0;
}