//
// Created by Emma on 2025/7/3.
//
#include<iostream>
using namespace std;

int main() {
    string a, b;
    double goal;
    cin >> goal >> a >> b;
    size_t all = a.size();
    int same = 0;
    for (int i = 0; i < all; i++) {
        if (a[i] == b[i]) {
            same++;
        }
    }
    if (same * 1.0 / double(all) >= goal) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}