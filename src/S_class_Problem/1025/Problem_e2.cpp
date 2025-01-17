//
// Created by Emma on 2025/1/17.
//
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int mycompare(char * target, char * source) {
    for (int i = 0; i < strlen(target); i ++) {
        if (isupper(target[i])) {
            target[i] = tolower(target[i]);
        }
    }
    for (int i = 0; i < strlen(source); i ++) {
        if (isupper(source[i])) {
            source[i] = tolower(source[i]);
        }
    }
    return strcmp(target, source);
}

int main() {
    int len = 0;
    char target[11], word[11];
    string source[1000001];
    cin >> target;
    while (scanf("%s", word) != EOF) {
        source[len ++] = word;
    }
    int ans = 0, index = 0, res = -1;
    bool flag = false;
    for (int i = 0; i < len; i ++) {
        // if (mycompare(target, source) == 0) {
        //     ans++;
        //     if (flag == false) {
        //         res = index;
        //         flag = true;
        //     }
        // }
        index++;
    }
    if (res == -1) {
        cout << res << endl;
    } else {
        cout << ans << " " << res << endl;
    }
    return 0;
}

