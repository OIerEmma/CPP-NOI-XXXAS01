//
// Created by Emma on 2025/7/4.
//
#include<iostream>
using namespace std;

string name[110];
int score[110];

int main() {
    int n, max_sc = -1, idx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> score[i] >> name[i];
        if (max_sc < score[i]) {
            max_sc = score[i];
            idx = i;
        }
    }
    cout << name[idx] << endl;
    return 0;
}