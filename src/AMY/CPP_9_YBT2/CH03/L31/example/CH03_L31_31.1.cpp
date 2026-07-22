//
// Created by Amy on 2026/7/10.
//
#include <iostream>
using namespace std;

int winner(char a, char b) {
    if (a == b) return 0;
    if ((a == 'S' && b == 'J') ||
        (a == 'J' && b == 'B') ||
        (a == 'B' && b == 'S')) {
        return 1;
        }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int xiaoyan = 0, xiaoke = 0;
    for (int i = 0; i < n; ++i) {
        char a, b;
        cin >> a >> b;
        int res = winner(a, b);
        if (res == 1) ++xiaoyan;
        else if (res == -1) ++xiaoke;
    }

    if (xiaoyan > xiaoke) cout << "xiaoyan" << endl;
    else if (xiaoke > xiaoyan) cout << "xiaoke" << endl;
    else cout << "QAQ" << endl;

    return 0;
}
