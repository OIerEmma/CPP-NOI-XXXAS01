//
// Created by Emma on 2025/4/13.
//
#include<iostream>
#include<algorithm>
using namespace std;

string all_str[100001];

bool cmp(string x, string y) {
    return x < y;
}

bool isA(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
    string line, str = "";
    int cnt = 1;

    /*getline(cin, line);
    for (int i = 0; i < line.size(); ) {
        if (isalpha(line[i])) {
            while (i < line.size() && isalpha(line[i])) {
                str += line[i++];
            }
            all_str[cnt++] = str;
            str = "";
        } else {
            // 找连续空格并重新开始一个单词
            while (i < line.size() && line[i] == ' ') {
                i++;
            }
        }
    }*/

    while (cin >> str) {
        all_str[cnt++] = str;
    }
    sort(all_str, all_str + cnt, cmp);

    for (int i = 1; i <= cnt; i++) {
        if (all_str[i-1] != all_str[i]) {
            cout << all_str[i] << endl;
        }
    }
    return 0;
}
