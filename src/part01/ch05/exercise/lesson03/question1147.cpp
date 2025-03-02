//
// Created by Emma on 2025/2/19.
//
#include<iostream>
using namespace std;

int main() {
    int n, max_sc = -1, index = 0;
    scanf("%d", &n);
    string name[100];
    int score[100];
    for (int i = 0; i < n; i++) {
        cin >> score[i] >> name[i];
        if (max_sc < score[i]) {
            max_sc = score[i];
            index = i;
        }
    }
    cout << name[index] << endl;
    return 0;
}
