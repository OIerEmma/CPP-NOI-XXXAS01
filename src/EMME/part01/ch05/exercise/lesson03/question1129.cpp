//
// Created by Emma on 2025/2/13.
//
#include<iostream>
using namespace std;

int main() {
    string n;
    getline(cin, n);
    int ans = 0;
    for (int i = 0; i < n.size(); i++) {
        if (isdigit(n[i]) != 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
