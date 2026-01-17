//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    int num, big0 = 0, sma0 = 0;
    for (; ;) {
        cin >> num;
        if (num == 0) {
            break;
        }
        if (num > 0) {
            big0++;
        } else {
            sma0++;
        }
    }
    cout << big0 << endl << sma0 << endl;
    return 0;
}
