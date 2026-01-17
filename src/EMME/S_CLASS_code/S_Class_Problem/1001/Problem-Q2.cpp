//
// Created by Emma on 2025/2/4.
//
#include<iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if(x <= 1 && x >= -1 && y <= 1 && y >= -1) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}