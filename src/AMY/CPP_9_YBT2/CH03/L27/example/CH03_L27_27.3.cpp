//
// Created by Amy on 2026/6/30.
//
#include<bits/stdc++.h>
using namespace std;
int n, m, s;
int main() {
    cin >> m;
    do {
        n++;
        s += n;
    }while(s <= m);
    cout << n;
    return 0;
}
