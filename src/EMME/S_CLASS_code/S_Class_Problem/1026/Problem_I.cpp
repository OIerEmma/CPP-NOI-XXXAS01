//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    int yuan10, yuan5, yuan1, money;
    cin >> money;
    yuan10 = money / 10;
    money %= 10;
    yuan5 = money / 5;
    money %= 5;
    yuan1 = money / 1;
    cout << "10yuan:" << yuan10 << endl;
    cout << "5yuan:" << yuan5 << endl;
    cout << "1yuan:" << yuan1;
    return 0;
}
