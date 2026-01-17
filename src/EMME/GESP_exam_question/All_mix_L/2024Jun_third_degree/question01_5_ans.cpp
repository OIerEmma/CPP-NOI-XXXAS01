//
// Created by Emma on 2025/2/12.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 26; i ++) {
        int j = (i + n) % 26;
        cout << char(j + 'A');
    }
    cout << endl;
    return 0;
}