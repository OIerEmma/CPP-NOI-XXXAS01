//
// Created by Emma on 2025/1/22.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int coordinate[6][6], max[6], min[6];
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> coordinate[i][j];
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i == 1) {
                min[j] = coordinate[i][j];
            } else {
                if (coordinate[i][j] < min[j])
                    min[j] = coordinate[i][j];
            }
            if (j == 1) {
                max[i] = coordinate[i][j];
            } else {
                if (coordinate[i][j] > max[i])
                    max[i] = coordinate[i][j];
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (max[i] == min[j]) {
                printf("%d %d %d", i, j, max[i]);
                continue;
            }
        }
    }
    return 0;
}
