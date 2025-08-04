//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, *pa, *pb;
    cin >> a >> b;
    pa = &a;
    pb = &b;
    int *pt = pa;
    pa = pb;
    pb = pt;
    cout << *pa << " " << *pb << endl;
    return 0;
}