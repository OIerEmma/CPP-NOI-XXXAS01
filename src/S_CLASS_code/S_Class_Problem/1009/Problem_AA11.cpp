//
// Created by Emma on 2025/7/30.
//
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    string a, b;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << a;
        if (a.size() == b.size()) {
            cout << " is equal long to ";
        } else if (a.size() > b.size()) {
            cout << " is longer than ";
        } else {
            cout << " is shorter than ";
        }
        cout << b << endl;
    }
    return 0;
}