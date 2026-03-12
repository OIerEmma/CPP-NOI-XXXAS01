//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    char s[3];
    cin >> s;
    char a = s[0], b = s[1];
    char x = 'a', y = 'b';
    int ans = 1;
    while (x != a || y != b) {
        y++;
        if (!isalpha(y)) {
            x++;
            y = 'a';
        }
        if (x == y) {
            y++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}