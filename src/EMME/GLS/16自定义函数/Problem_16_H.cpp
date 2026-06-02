//
// Created by Emme.Kwok on 2026/5/30.
//
#include<iostream>
using namespace std;

const int ss[5][5] {
    {0, 1, 2, 3, 4},
    {1, 2, 0, 3, 4},
    {2, 3, 1, 4, 0},
    {3, 4, 2, 1, 0},
    {4, 3, 2, 1, 0}
};
const string t[5] = {"S", "M", "L", "XL", "XXL"};
int n[5];
string s;
int f() {
    if (s[0] == 'S') return 0;
    if (s[0] == 'M') return 1;
    if (s[0] == 'L') return 2;
    if (s.size() == 2) return 3;
    return 4;
}

int main() {
    int k, x, idx;
    for (int i = 0; i < 5; i++) cin >> n[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> s;
        x = f();
        for (int j = 0; j < 5; j++) {
            idx = ss[x][j];
            if (n[idx]) {
                n[idx]--;
                cout << t[idx] << endl;
                break;
            }
        }
    }
    return 0;
}