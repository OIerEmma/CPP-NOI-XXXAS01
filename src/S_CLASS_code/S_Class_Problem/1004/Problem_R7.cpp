//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

struct p {
    string name;
    double tem;
    int c;
} a[210];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].tem >> a[i].c;
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].tem >= 37.5 && a[i].c == 1) {
            cout << a[i].name << endl;
            num++;
        }
    }
    cout << num << endl;
    return 0;
}