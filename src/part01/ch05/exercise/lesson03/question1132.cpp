//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string player1[n], player2[n];
    for (int i = 0; i < n; i++) {
        cin >> player1[i] >> player2[i];
        if (player1[i] == player2[i]) {
            printf("Tie\n");
            continue;
        } else {
            if (player1[i] == "Rock") {
                if (player2[i] == "Scissors") {
                    printf("Player1\n");
                } else {
                    printf("Player2\n");
                }
                continue;
            } else if (player1[i] == "Scissors") {
                if (player2[i] == "Paper") {
                    printf("Player1\n");
                } else {
                    printf("Player2\n");
                }
                continue;
            } else {
                if (player2[i] == "Rock") {
                    printf("Player1\n");
                } else {
                    printf("Player2\n");
                }
                continue;
            }
        }
    }
    return 0;
}
