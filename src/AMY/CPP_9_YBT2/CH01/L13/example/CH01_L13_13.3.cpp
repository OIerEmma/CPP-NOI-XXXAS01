//
// Created by Amy on 2026/6/6.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, a2, b2, c2;
    scanf("%d:%d:%d",&a2,&b2,&c2);
    scanf("%d:%d:%d",&a,&b,&c);
    printf("%d",(a*3600+b*60+c)-(a2*3600+b2*60+c2));
    return 0;
}