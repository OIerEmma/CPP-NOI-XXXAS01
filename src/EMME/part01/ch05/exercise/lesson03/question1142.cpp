//
// Created by Emma on 2025/2/16.
//
#include<iostream>
using namespace std;

int main() {
    string n;
    int ans[300], temp = 0, j = 0;
    getline(cin, n);
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == ' ') {
            ans[j++] = temp;
            while(n[++i] == ' ');
            i--;
            temp = 0;
        } else {
            temp++;
        }
    }
    ans[j++] = temp;
    for (int i = 0; i < j; i++) {
        if (i == j - 1) {
            printf("%d", ans[i]);
        } else {
            printf("%d,", ans[i]);
        }
    }
    return 0;
}
