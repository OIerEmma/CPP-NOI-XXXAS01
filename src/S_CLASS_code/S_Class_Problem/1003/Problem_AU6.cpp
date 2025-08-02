//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

string p1[110], p2[110];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> p1[i] >> p2[i];
        if (p1[i] == p2[i]) {
            cout << "Tie" << endl;
            continue;
        } else {
            if (p1[i] == "Rock") {
                if (p2[i] == "Scissors") {
                    cout << "Player1" << endl;
                } else {
                    cout << "Player2" << endl;
                }
                continue;
            } else if (p1[i] == "Scissors") {
                if (p2[i] == "Paper") {
                    cout << "Player1" << endl;
                } else {
                    cout << "Player2" << endl;
                }
                continue;
            } else {
                if (p2[i] == "Rock") {
                    cout << "Player1" << endl;
                } else {
                    cout << "Player2" << endl;
                }
                continue;
            }
        }
    }
    return 0;
}