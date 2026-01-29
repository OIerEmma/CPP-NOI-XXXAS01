//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

char s[110];

void reverse(char *str) {
    for (int i = 0; i <= strlen(str) / 2; i++) {
        swap(str[i], str[strlen(str) - i - 1]);
    }
}

int main() {
    char *ps = s;
    cin >> s;
    reverse(ps);
    cout << s << endl;
    return 0;
}