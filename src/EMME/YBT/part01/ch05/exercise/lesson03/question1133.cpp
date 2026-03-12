//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        printf("%c", static_cast<char>(s[i] + s[i + 1]));
    }
    printf("%c", static_cast<char>(s[s.size() - 1] + s[0]));
    return 0;
}