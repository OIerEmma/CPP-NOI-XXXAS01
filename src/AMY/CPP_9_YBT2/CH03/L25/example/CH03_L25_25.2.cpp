//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
char i;
int main() {
    for (i = 'a'; i <= 'z'; i++)
        cout << i << ' ';
    cout << endl;
    i = 'Z';
    while (i >= 'A') {
        cout << i << ' ';
        i--;
    }
    return 0;
}
