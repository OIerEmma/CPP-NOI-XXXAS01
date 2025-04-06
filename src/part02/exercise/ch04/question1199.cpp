//
// Created by Emma on 2025/3/14.
//
#include<iostream>
#include<cstring>
using namespace std;
char str[6], ans[6];
bool check[6];
size_t len;

void arrange(const int pos) {
    if (pos == len) {
        for (int i = 0; i < len; i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < len; i++) {
        if (check[i] == false) {
            check[i] = true;
            ans[pos] = str[i];
            arrange(pos + 1);
            check[i] = false;
        }
    }
}

int main() {
    cin >> str;
    len = strlen(str);
    arrange(0);
    return 0;
}
