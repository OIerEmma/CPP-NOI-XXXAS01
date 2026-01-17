//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

void print(int num) {
    if (num >= 10) {
        cout << char(65 + (num - 10));
    } else {
        cout << num;
    }
}

void recursive(int num, int data) {
    if (num < data) {
        print(num);
        return;
    }
    recursive(num / data, data);
    print(num % data);
}

int main() {
    int n, m;
    cin >> n >> m;
    recursive(n, m);
    return 0;
}