//
// Created by Emma on 2025/1/19.
//
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n + 1];
    array[0] = n;
    int max, max_x;
    int index[n + 1] = {0};
    memset(index, 0, sizeof(index));
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
        if (i == 1) {
            max = array[i];
            max_x = i;
        } else {
            if (array[i] > max) max = array[i];
            max_x = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        index[array[i]]++;
    }
    for (int i = 0; i < max + 1; i++) {
        printf("%d\n", index[i]);
    }
    return 0;
}
