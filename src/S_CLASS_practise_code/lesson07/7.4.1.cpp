//
// Created by Emma on 2025/1/23.
//
#include<iostream>
using namespace std;

int s, e;
void show() {
    for(int i = s; i <= e; i++) {
        printf("%d\n", i);
    }
}
int main() {
    cin >> s >> e;
    show();
    return 0;
}