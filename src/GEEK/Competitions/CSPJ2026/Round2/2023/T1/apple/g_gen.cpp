//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    mt19937 rng(atoi(argv[1]));
    int n = rng() % 20 + 1;
    cout << n << endl;
    return 0;
}