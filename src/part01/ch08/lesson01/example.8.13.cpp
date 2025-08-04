//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

void t1() {
    cout << "test1" << endl;
}

void t2() {
    cout << "test2" << endl;
}

void t3() {
    cout << "test3" << endl;
}

void t4() {
    cout << "test4" << endl;
}

void t5() {
    cout << "test5" << endl;
}

typedef void(*LP)();

int main() {
    LP a[5] = {t1, t2, t3, t4, t5};
    int x;
    cin >> x;
    a[x]();
    return 0;
}