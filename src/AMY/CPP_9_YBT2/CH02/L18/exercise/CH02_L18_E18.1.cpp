//
// Created by Amy on 2026/6/14.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    cout << (m > 25 ? 60 - m + 25 : 25 - m);
    //if (m > 25) {
        //cout << 60 - m + 25;
    //}else {
        //cout << 25 - m;
    //}
    return 0;
}