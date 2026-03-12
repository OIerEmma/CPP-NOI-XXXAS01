//
// Created by Emma on 2025/2/13.
//
#include<iostream>
using namespace std;

int main() {
    int count[26];
    string n;
    cin >> n;
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n.size(); i++) {
        count[int(n[i]) - 97]++;
    }
    for (int i = 0; i < n.size(); i++) {
        if (count[int(n[i]) - 97] == 1) {
            printf("%c\n", n[i]);
            return 0;
        }
    }
    printf("no\n");
    return 0;
}
