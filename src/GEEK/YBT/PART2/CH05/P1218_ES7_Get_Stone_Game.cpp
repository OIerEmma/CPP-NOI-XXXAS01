//
// Created by Geek.Kwok on 3/16/26.
//
#include <bits/stdc++.h>
using namespace std;

int a, b, turn;

void dfs(int a, int b) {
    if (a == 0 || b == 0) {
        turn++;
        return;
    }
    int maxab = max(a, b), minab = min(a, b);
    if (maxab / minab >= 2 || maxab == minab) {
        turn++;
        return;
    }
    // 24 15 = 9
    // a: 15 | 9 15 -> 15 9
    // b: 9 | 6 9 -> 9 6
    // a: 6 | 3 6 -> 6 3
    // b: 6 | 0 3
    turn++;
    dfs(minab, maxab - minab);
}

int main() {
    do {
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
        if (turn % 2) {
            cout << "win" << endl;
        } else {
            cout << "lose" << endl;
        }
    } while (true);
    return 0;
}