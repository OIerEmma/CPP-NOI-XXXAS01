//
// Created by Emma on 2025/7/30.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = int(s.size() - 1), side = int(s.size() + 2) / 3, mid = int(s.size()) - side * 2;
    for (int i = 0; i < side - 1; i++) {
        cout << s[a++];
        for (int j = 1; j <= mid; j++) {
            cout << " ";
        }
        cout << s[b--];
        if (i != side - 1) {
            cout << endl;
        }
    }
    for (int i = a; i <= b; i++) {
        cout << s[i];
    }
    return 0;
}