//
// Created by Emma on 2025/8/12.
//
#include<iostream>
using namespace std;

int a[200], b[200], c[200], i;
char n[200], n1[200], n2[200];

int main() {
    cin >> n1 >> n2;
    if (strlen(n1) < strlen(n2) || strlen(n1) == strlen(n2) && strcmp(n1, n2) < 0) {
        strcpy(n, n1);
        strcpy(n1, n2);
        strcpy(n2, n);
        cout << "-";
    }
    size_t lena = strlen(n1), lenb = strlen(n2), lenc;
    for (i = 0; i < lena; i++) {
        a[lena - i] = int(n1[i] - '0');
    }
    for (i = 0; i < lenb; i++) {
        b[lenb - i] = int(n2[i] - '0');
    }
    i = 1;
    while (i <= lena || i <= lenb) {
        if (a[i] < b[i]) {
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];
        i++;
    }
    lenc = i;
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    for (i = int(lenc); i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
