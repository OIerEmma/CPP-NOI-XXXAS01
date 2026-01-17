//
// Created by Emma on 2025/2/4.
//
#include<iostream>
using namespace std;

int main() {
    int weight;
    char worry;
    cin >> weight >> worry;
    int money = 0;
    if (weight <= 1000) {
        if(worry == 'y') {
            money += 13;
        } else {
            money += 8;
        }
    } else {
        if(worry == 'y') {
            money += (weight / 500 + 1) * 4 + 5;
        } else {
            money += (weight / 500 + 1) * 4;
        }
    }
    printf("%d", money);
    return 0;
}