//
// Created by Emma on 2024/12/1.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n > 0) {
        cout << "positive" << endl;
    } else if(n == 0) {
        cout << "zero" << endl;
    } else {
        cout << "negative" << endl;
    }
    return 0;
}