//
// Created by Emma on 2024/12/21.
//
#include<iostream>
using namespace std;

int main() {
    int N, m, num, value = 0;
    cin >> N >> m;
    for (int i = 1; i <= N; i ++) {
        cin >> num;
        if (num == m) {
            value ++;
        }
    }
    cout << value << endl;
    return 0;
}