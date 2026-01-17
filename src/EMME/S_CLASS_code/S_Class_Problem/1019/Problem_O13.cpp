//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

int main() {
    int h, l;
    cin >> h >> l;
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < h; j++) {
            if (i + j == h && i * 2 + j * 4 == l) {
                cout << "xiang:" << j << " niao:" << i << endl;
                break;
            }
        }
    }
    return 0;
}