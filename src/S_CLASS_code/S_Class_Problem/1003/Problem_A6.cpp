//
// Created by Emma on 2025/6/30.
//
#include<iostream>
using namespace std;

int s[1024], h[1024];

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> s[i] >> h[i];
    }
    int ans = 8;
    for (int i = 0; i < 7; i++) {
        if (s[i] + h[i] > 8) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}