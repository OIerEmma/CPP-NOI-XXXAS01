//
// Created by Emma on 2025/2/19.
//
#include<iostream>
using namespace std;

int main() {
    string input;
    bool flag = true;
    cin >> input;
    for (int i = 0; i < input.size() / 2; i++) {
        if (input[i] != input[input.size() - i - 1]) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
    return 0;
}