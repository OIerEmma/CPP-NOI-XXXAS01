//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    double n;
    cin >> n;
    if (n < 6 && n >= 2) {
        cout << "YouErYuan" << endl;
    } else if (n >= 6 && n < 12) {
        cout << "XiaoXue" << endl;
    } else if (n >= 12 && n < 15){
        cout << "ChuZhong" << endl;
    } else if (n >= 15 && n < 18){
        cout << "GaoZhong" << endl;
    }
    return 0;
}