//
// Created by Emma on 2025/2/8.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n, gold, silver, metal, allgold = 0, allsilver = 0, allmetal = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> gold >> silver >> metal;
        allgold += gold;
        allsilver += silver;
        allmetal += metal;
    }
    cout << allgold << " " << allsilver << " " << allmetal << " " << allgold + allsilver + allmetal<< endl;
    return 0;
}