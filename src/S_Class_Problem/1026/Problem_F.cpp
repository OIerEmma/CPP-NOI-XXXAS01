//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, max;
    cin >> a >> b >> c;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    if (max < c){
        max = c;
    }
    cout << max << endl;
    return 0;
}