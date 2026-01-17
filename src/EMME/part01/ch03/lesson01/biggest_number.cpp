//
// Created by Emma on 2024/11/30.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    //the first method
    float a, b, c, maxn;
    cin >> a >> b >> c;
    if((a >= b) && (a >= c)) {
        maxn = a;
    } else if((b >= a) && (b >= c)){
        maxn = b;
    } else {
        maxn = c;
    }
    cout << maxn << endl;
    return 0;
    /*
    the second method
    float a, b, c, maxn;
    cin >> a >> b >> c;
    maxn = a;
    if(b > maxn) {
        maxn = b;
    } if(c > maxn){
        maxn = c;
    }
    cout << maxn << endl;
     */
}
