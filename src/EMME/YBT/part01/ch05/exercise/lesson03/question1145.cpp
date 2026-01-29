//
// Created by Emma on 2025/2/18.
//
#include<iostream>
using namespace std;

int main() {
    string line;
    char n[2000];
    cin >> line;
    memset(n, '\0', sizeof(n));
    int pos = 0, j = 0, i;
    for (i = pos; i < line.size(); i++) {
        if (line[pos] != line[i]) {
            string cnt = to_string(i - pos);
            for (int k = 0; k < cnt.size(); k++) {
                n[j++] = cnt[k];
            }
            n[j++] = line[pos];
            pos = i;
        }
    }
    string cnt = to_string(i - pos);
    for (int k = 0; k < cnt.size(); k++) {
        n[j++] = cnt[k];
    }
    n[j++] = line[pos];
    cout << n << endl;
    return 0;
}
