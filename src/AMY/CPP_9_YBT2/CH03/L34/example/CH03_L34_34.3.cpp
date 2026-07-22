//
// Created by Amy on 2026/7/13.
//
#include<bits/stdc++.h>
using namespace std;
char c;
int len, cnt;
int main() {
    while (scanf("%c",&c) != EOF) {
        if (c >= '0' && c <= '9') cnt++;
    }
    cout << cnt;
    return 0;
}