//
// Created by Amy on 2026/7/19.
//
#include <iostream>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    for (int i = 0; i < T; ++i) {
        int code;
        cin >> code;
        cout << static_cast<char>(code);
    }
    return 0;
}
