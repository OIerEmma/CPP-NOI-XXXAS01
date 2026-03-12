//
// Created by Geek.Kwok on 2026/1/27.
//
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
char ch[maxn];
size_t len;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> ch;
        len = strlen(ch);
        // find 101 pattern
        size_t i = 0;
        while (i < len) {
            // find first 1
            while (ch[i] == '0') {
                i++;
            }
            int cnt = 0; // count 1
            while (ch[i] == '1') {
                i++;
                cnt++;
            }
            // find 0
        }
    }
    return 0;
}