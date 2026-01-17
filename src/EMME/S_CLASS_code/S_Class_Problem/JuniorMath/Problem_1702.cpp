//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int beau[100010];

int main() {
    int n, j = 1;
    for (int i = 1; i <= 100000; i++) {
        for (; ; j++) {
            if (j % 3 == 0 || j % 5 == 0) {
                beau[i] = j;
                j++;
                break;
            }
        }
    }
    while (cin >> n) {
        cout << beau[n] << endl;
    }
    return 0;
}