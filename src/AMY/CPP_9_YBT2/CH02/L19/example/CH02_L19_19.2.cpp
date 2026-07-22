//
// Created by Amy on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;
int x, y;double z;
int main() {
    scanf("%d%d",&x,&y);
    z = (x - 100) * 0.9;
    if(y > 1.1 * z) printf("fat");
    else if(y < z * 0.9) printf("thin");
    else printf("standard");
    return 0;
}