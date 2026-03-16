//
// Created by Emme.Kwok on 2026/3/16.
//
#include<iostream>
using namespace std;

int a, b, turn;

void dfs(int na, int nb) { // true:first false:second
    if (na == 0 || nb == 0) {
        turn++;
        return;
    }
    if (na / nb >= 2 || na == nb) {
        turn++;
        return;
    }
    turn++;
    dfs(nb, na - nb);
}

int main() {
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        int maxab = max(a, b), minab = min(a, b);
        if (maxab / minab >= 2 || maxab == minab) {
            cout << "win" << endl;
            continue;
        }
        turn = 0;
        dfs(maxab, minab);
        if (turn % 2 != 0) {
            cout << "win" << endl;
        } else {
            cout << "lose" << endl;
        }
    }
    return 0;
}