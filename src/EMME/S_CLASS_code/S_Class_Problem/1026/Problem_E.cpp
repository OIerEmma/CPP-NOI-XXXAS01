//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    double distanse, money = 0;
    cin >> distanse;
    if (distanse <= 3) {
        money += 10.0;
    } else if (distanse <= 5) {
        money += 10.0;
        money += (distanse - 3) * 1.8;
    } else if (distanse > 5){
        money += 10.0;
        money += 2 * 1.8;
        money += (distanse - 5) * 2.7;
    }
    printf("%.2lf", money);
    return 0;
}