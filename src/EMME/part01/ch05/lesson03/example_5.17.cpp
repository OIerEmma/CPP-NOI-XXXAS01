//
// Created by Emma on 2025/2/11.
//
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char st[100];
    gets(st);
    for (int i = 1; i < strlen(st); i++) {
        cout << st[i];
    }
    return 0;
}