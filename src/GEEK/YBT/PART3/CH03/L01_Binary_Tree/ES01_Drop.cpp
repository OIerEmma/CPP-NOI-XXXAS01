//
// Created by Geek.Kwok on 2026/4/23.
//
#include <iostream>
using namespace std;

int D, I, ans;
bool f[1<<20];

int main() {
    cin >> D >> I;
    for (int i = 1; i <= I; i++) {
        int depth = 1, idx = 1;
        while (depth < D) {
            f[idx] = !f[idx];
            if (f[idx]) idx = 2 * idx;
            else idx = 2 * idx + 1;
            depth++;
        }
        ans = idx;
    }
    cout << ans << endl;
    return 0;
}