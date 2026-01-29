//
// Created by Emma on 2025/2/10.
//
#include<iostream>
#include<string>
using namespace std;
const int n = 61;
char s1[n], s2[n], x[n], t[n];
int len1, len2;

int main() {
    cin >> s1 >> s2;
    if (strlen(s1) < strlen(s2)) {
        strcpy(t, s1);
        strcpy(s1, s2);
        strcpy(s2, t);
    }
    strcpy(x, s1);
    if (strstr(strcat(s1, x), s2) == nullptr) {
        printf("false\n");
    } else {
        printf("true\n");
    }
    return 0;
}
