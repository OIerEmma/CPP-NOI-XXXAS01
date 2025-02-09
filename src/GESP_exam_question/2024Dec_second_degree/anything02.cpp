//
// Created by Emma on 2025/2/7.
//
#include<iostream>
using namespace std;

int main() {
    int cnt = 0;
    for(int i = 0; i < 5; i ++) {
        if(i % 2) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
