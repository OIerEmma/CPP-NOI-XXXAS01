//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == 'A') {
            printf("T");
        } else if (n[i] == 'T') {
            printf("A");
        } else if (n[i] == 'G') {
            printf("C");
        } else {
            printf("G");
        }
    }
    return 0;
}