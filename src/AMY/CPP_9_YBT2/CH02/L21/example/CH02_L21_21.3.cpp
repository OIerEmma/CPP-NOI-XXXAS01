//
// Created by Amy on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;
char a;
int main() {
    cin >> a;
    if (a >= 'A' && a <= 'Z') cout << "upper";
    else if (a >= 'a' && a <= 'z') cout << "lower";
    else if (a >= '0' && a <= '9') cout << "digit";
    else  cout <<"other";
    return 0;
}
