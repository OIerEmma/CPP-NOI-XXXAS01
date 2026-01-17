//
// Created by Emma on 2025/2/23.
//
#include<iostream>
using namespace std;
string k, c;

int main() {
    getline(cin, k);
    getline(cin, c);
    size_t len = k.size(), len1 = c.size();
    for (int i = 0; i < len; i++) {
        k[i] = char(toupper(k[i]));
    }
    for (int i = 0, j = 0; i < len1; i++) {
        if (isupper(c[i])) {
            c[i] -= k[j] - 'A';
            j++;
            if (c[i] < 'A') {
                c[i] = 'Z' - ('A' - c[i]) + 1;
            }
        } else {
            c[i] -= int(k[j]) - int('A');
            j++;
            if (c[i] < 'a') {
                c[i] = 'z' - ('a' - c[i]) + 1;
            }
        }
        if (j > len - 1)j = 0;
    }
    cout << c;
    return 0;
}
