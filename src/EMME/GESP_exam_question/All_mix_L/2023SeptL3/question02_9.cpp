//
// Created by Emma on 2025/3/9.
//
#include<iostream>
using namespace std;

int main() {
    int n, twodata = 1, eightdata = 1, tendata = 1, sixteendata = 1;
    string str;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] > 'F') {
                twodata = 0, eightdata = 0, tendata = 0, sixteendata = 0;
                break;
            }
            sixteendata = 1;
            if (str[j] >= 'A') {
                twodata = 0, eightdata = 0, tendata = 0;
                break;
            }
            if (str[j] >= '8') {
                twodata = 0, eightdata = 0;
            } else if (str[j] >= '2') {
                twodata = 0;
            }
        }
        printf("%d %d %d %d\n", twodata, eightdata, tendata, sixteendata);
        twodata = 1, eightdata = 1, tendata = 1, sixteendata = 1;
    }
    return 0;
}