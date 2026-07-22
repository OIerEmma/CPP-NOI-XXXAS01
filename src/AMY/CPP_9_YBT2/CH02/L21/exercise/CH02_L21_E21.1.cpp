//
// Created by Amy on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;
int a;
int main() {
    cin >> a;
    if (a >= 0 && a <= 3) cout << "infant";
    else if (a >= 4 && a <= 12) cout << "child";
    else if (a >= 13 && a <= 18) cout << "youngster";
    else if (a >= 19 && a <= 25)  cout <<"youth";
    return 0;
}
