//
// Created by Amy on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;
int x;

int main() {
    cin >> x;
    if (x > 30) cout << "Fail";
    else if (x <= 10) printf("%.2lf", 0.2 + x * 0.80);
    else if (x > 10 && x <= 20) printf("%.2lf", 0.2 + x * 0.75);
    else if (x > 20 && x <= 30) printf("%.2lf", 0.2 + x * 0.70);
    return 0;
}
