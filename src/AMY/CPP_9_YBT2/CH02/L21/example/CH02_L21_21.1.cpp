//
// Created by Amy on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;
int h;
int main() {
    cin >> h;
    if (h <= 150) cout << "S";
    else if (h <= 160) cout << "M";
    else if (h <= 170) cout << "L";
    else if (h <= 180) cout << "XL";
    else  cout << "XXL";
    return 0;
}
