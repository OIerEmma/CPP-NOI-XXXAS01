//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    string n;
    getline(cin, n);
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == 'z') {
            printf("a");
        } else if (n[i] == 'Z') {
            printf("A");
        } else if (n[i] >= 'A' && n[i] <= 'Z' || n[i] >= 'a' && n[i] <= 'z') {
            printf("%c", char(int(n[i]) + 1));
        } else {
            printf("%c", n[i]);
        }
    }
    return 0;
}
