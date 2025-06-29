//
// Created by Emma on 2025/6/14.
//
#include<iostream>
using namespace std;

string str[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    string s;
    int two_data, eig_data, ten_data, twe_data;
    for (int i = 0; i < n; i++) {
        s = str[i];
        two_data = 0;eig_data = 0;ten_data = 0;twe_data = 0;
        int j;
        bool flag = true;
        for (j = 0; j < s.size(); j++) {
            if (s[j] > 'F') {
                two_data = 0;eig_data = 0;ten_data = 0;twe_data = 0;
                flag = false;
                break;
            }
            if (s[j] >= 'A' && s[j] <= 'F') {
                two_data = 0;eig_data = 0;ten_data = 0;twe_data = 1;
                flag = false;
                break;
            }
            if (s[j] >= '8') {
                ten_data = 1;twe_data = 1;two_data = 0;eig_data = 0;
                flag = false;
                break;
            }
            if (s[j] >= '2') {
                eig_data = 1;ten_data = 1;twe_data = 1;two_data = 0;
                flag = false;
            }
        }
        if (flag) {
            eig_data = 1;ten_data = 1;twe_data = 1;two_data = 1;
        }
        printf("%d %d %d %d\n", two_data, eig_data, ten_data, twe_data);
    }
    return 0;
}