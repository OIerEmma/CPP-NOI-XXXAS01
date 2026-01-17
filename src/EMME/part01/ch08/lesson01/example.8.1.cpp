//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, s, t, *pa, *pb;
    pa = &a;
    pb = &b;
    a = 10;
    b = 20;
    s = *pa + *pb;
    t = *pa * *pb;
    cout << pa << " " << *pa << endl;
    printf("a=%d, b=%d\n", *pa, *pb);
    printf("s=%d, t=%d\n", s, t);
    return 0;
}