//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

int dtob_one_num(int num) {
    int ans = 0;
    while (num) {
        if (num % 2 == 1) {
            ans++;
        }
        num /= 2;
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int i = n + 1, tar = dtob_one_num(n);
        while (dtob_one_num(i) != tar) {
            i++;
        }
        cout << i << endl;
    }
    return 0;
}