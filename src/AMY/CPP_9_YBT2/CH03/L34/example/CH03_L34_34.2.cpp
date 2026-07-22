//
// Created by Amy on 2026/7/13.
//
#include<bits/stdc++.h>
using namespace std;
char c;
int main() {
    while (scanf("%c",&c) == 1) {
        if (c == 'A') cout << 'T';
        else if (c == 'T') cout << 'A';
        else if (c == 'C') cout << 'G';
        else if (c == 'G') cout << 'C';
;    }
    return 0;
}