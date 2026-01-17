//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % 6 == 0 || i % 8 == 0) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}