//
// Created by Amy on 2026/6/5.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    scanf("%d",&x);
    printf("%02d:%02d:%02d", x/3600,(x%3600)/60,x%60);
    return 0;
}