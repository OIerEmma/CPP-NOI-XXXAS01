//
// Created by Emma on 2025/7/3.
//
#include<iostream>
using namespace std;

int main() {
    string n;
    getline(cin, n);
    char ans[100];
    for (int i = 0; i < n.size(); i++) {
        if (n[i] >= 'a' && n[i] <= 'z') {
            ans[i] = char(n[i] - 32);
        } else {
            ans[i] = n[i];
        }
    }
    for (int i = 0; i < n.size(); i++) {
        printf("%c", ans[i]);
    }
    return 0;
}