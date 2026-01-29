//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int t(int a) {
    return a;
}

int main() {
    cout << t << endl;
    int (*p)(int a);
    p = t;
    cout << p(5) << "," <<(*p)(10) << endl;
    return 0;
}