//
// Created by Emma on 2025/8/2.
//
#include<iostream>
#include<cstring>
using namespace std;

char s[110];

void swapp(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void work(char *str) {
    size_t len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        swapp(str[i], str[len - i - 1]);
    }
}

int main() {
    char *str = s;
    gets(s);
    work(str);
    printf("%s\n", s);
    return 0;
}
