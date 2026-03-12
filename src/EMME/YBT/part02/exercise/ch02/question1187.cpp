//
// Created by Emma on 2025/4/18.
//
#include<iostream>
using namespace std;

int num[26];

int main() {
    memset(num, 0, sizeof(num));
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        num[str[i] - 97]++;
    }
    int max_num = 0, max_index;
    for (int i = 0; i < 26; i++) {
        if (max_num < num[i]) {
            max_num = num[i];
            max_index = i;
        }
    }
    printf("%c %d\n", char(max_index + 97), max_num);
    return 0;
}
