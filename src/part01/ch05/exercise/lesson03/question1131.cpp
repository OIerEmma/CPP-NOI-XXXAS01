//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    string a, b;
    double goal;
    int same = 0;
    cin >> goal;
    cin >> a >> b;
    const size_t all = a.size();
    for (int i = 0; i < all; i++) {
        if (a[i] == b[i]) {
            same++;
        }
    }
    if (same * 1.0 / static_cast<double>(all) >= goal) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}