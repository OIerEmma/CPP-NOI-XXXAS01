//
// Created by Amy on 2026/6/23.
//
#include<bits/stdc++.h>
using namespace std;
int x;
int main() {
    cin >> x;
    switch(x) {
        case 1:
            cout << "寿仙菇"; break;
        case 2:
            cout << "酒糟芋"; break;
        case 3:
            cout << "下山笋"; break;
        case 4:
            cout << "太师豆腐"; break;
        case 5:
            cout << "孝子鱼"; break;
        case 6:
            cout << "猪全福"; break;
        default:
            cout << "无此编号的菜";
    }
    return 0;
}