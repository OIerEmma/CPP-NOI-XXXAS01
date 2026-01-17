//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

bool head_is_num(string n) {
    if (int(n[0]) > 48 && int(n[0]) < 57) {
        return true;
    } else {
        return false;
    }
}

bool letter(string n, int i) {
    if (int(n[i]) >= 65 && int(n[i]) <= 90 || int(n[i]) >= 97 && int(n[i]) <= 122) {
        return true;
    } else {
        return false;
    }
}

bool middle_is_num(string n, int i) {
    if (int(n[i]) >= 48 && int(n[i]) <= 57) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string n;
    cin >> n;
    if (head_is_num(n)) {
        printf("no\n");
    } else {
        if (!(letter(n, 0) || n[0] == '_')) {
            printf("no\n");
        } else {
            bool flag = true;
            for (int i = 1; i < n.size(); i++) {
                if (n[i] != '_' && !(letter(n, i) || middle_is_num(n, i))) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}
