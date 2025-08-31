//
// Created by Emma on 2025/8/6.
//
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int l = max({n, m, k});
    for (int red = 1; red < l; red++) {
        for (int blue = 1; blue < l; blue++) {
            for (int yell = 1; yell < l; yell++) {
                if (red + blue == n && blue + yell == m && red + yell == k) {
                    cout << "red:" << red;
                    cout << " blue:" << blue;
                    cout << " yellow:" << yell << endl;
                    break;
                }
            }
        }
    }
    return 0;
}