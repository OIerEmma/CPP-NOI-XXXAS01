//
// Created by Emma on 2025/4/2.
//
#include<iostream>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int idx[str.size()], cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                idx[cnt++] = i;
            } else if (str[i] == ')') {
                if (cnt > 0 && str[idx[cnt - 1]] == '(') {
                    cnt--;
                } else {
                    idx[cnt++] = i;
                }
            }
        }
        cout << str << endl;
        for (int j = 0, k = 0; j < str.size(); j++) {
            if (j == idx[k] && k < cnt) {
                k++;
                if (str[j] == '(') {
                    printf("$");
                } else if (str[j] == ')') {
                    printf("?");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
