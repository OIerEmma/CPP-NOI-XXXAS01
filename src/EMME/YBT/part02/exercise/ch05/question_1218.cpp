//
// Created by Emme.Kwok on 2026/3/16.
//
#include<iostream>
using namespace std;

int a, b;
bool isfinish = true;

void dfs(int na, int nb, bool flag) { // true:first false:second
    if (!isfinish) return;
    if (na == 0 || nb == 0) {
        if (flag) cout << "win" << endl;
        else cout << "lose" << endl;
        isfinish = false;
        return;
    }
    if (na >= nb) {
        if (na / nb >= 2) {
            if (flag) cout << "win" << endl;
            else cout << "lose" << endl;
            isfinish = false;
            return;
        }
        dfs(na, nb, !flag);
    } else {
        if (nb / na >= 2) cout << "lose" << endl;
        else dfs(na, nb, true);
    }
    if (na > nb) {
        for (int i = 1; i <= na; i++) {
            if (i % nb == 0) dfs(na, nb - i, !flag);
        }
    } else if (na < nb) {
        for (int i = 1; i <= nb; i++) {
            if (i % na == 0) dfs(na - i, nb, !flag);
        }
    } else {
        if (flag) cout << "win" << endl;
        else cout << "lose" << endl;
    }
}

int main() {
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        if (a >= b) {
            if (a / b >= 2) cout << "win" << endl;
            else dfs(a, b, true);
        } else {
            if (b / a >= 2) cout << "lose" << endl;
            else dfs(a, b, true);
        }
        isfinish = true;
        dfs(a, b, true);
    }
    return 0;
}