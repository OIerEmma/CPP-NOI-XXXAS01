//
// Created by Emma on 2025/2/20.
//
#include<iostream>
using namespace std;

int main() {
    int money = 0, remain = 0, use, save = 0;
    for (int i = 1; i <= 12; i++) {
        cin >> use;
        money += 300;
        money -= use;
        if (money >= 100) {
            remain = money % 100;
            save += (money - remain);
            money = remain;
        } else if (money < 0) {
            cout << "-" << i << endl;
            break;
        }
    }
    if (money >= 0) {
        money += (save + save / 5);
        cout << money << endl;
    }
    return 0;
}
