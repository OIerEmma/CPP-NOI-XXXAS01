//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int sum, x;
int main() {
    do {
        sum += x;
        cin >> x;
    }while(x != -1);
    cout << sum;
    return 0;
}
