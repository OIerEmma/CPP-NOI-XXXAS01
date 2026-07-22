//
// Created by Amy on 2026/7/19.
//
#include<bits/stdc++.h>
using namespace std;

char a;

int main() {
    a = getchar();
    if (isupper(a)) cout << "upper";
    else if (islower(a)) cout << "lower";
    else if (isdigit(a)) cout << "digit";
    else cout << "other";
    return 0;
}