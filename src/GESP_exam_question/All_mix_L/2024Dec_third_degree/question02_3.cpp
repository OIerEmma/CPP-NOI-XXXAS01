//
// Created by Emma on 2025/2/8.
//
#include<iostream>
using namespace std;

const string grid[4][5] = {
    {".....", ".***.", ".***.", ".***.", "....."}, // grid[0][0~4]
    {"****.", "****.", "****.", "****.", "****."}, // grid[1][0~4]
    {".....", "****.", ".....", ".****", "....."}, // grid[2][0~4]
    {".....", "****.", ".....", "****.", "....."} // grid[3][0~4]
};

int main() {
    int n, a[7], len = 0;
    scanf("%d", &n);
    // n = 12230
    // a[] = {0, 3, 2, 2, 1}
    while (n > 0) {
        a[len++] = n % 10;
        n /= 10;
    }
    for (int j = 0; j < 5; j ++) {
        for (int i = len - 1; i >= 0; i --) {
            // a[i] = a[4] = 1;
            // grid[a[i]][j] = grid[1][0] = "****." ;
            // printf("%s", grid[a[i]][j]);
            cout << grid[a[i]][j];
        }
        cout << endl;
    }
    return 0;
}
