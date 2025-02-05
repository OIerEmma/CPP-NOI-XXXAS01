//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    d += 21;
    if(m == 4 || m == 6 || m == 9 || m == 11) {
        if(d > 30) {
            d -= 30;
            m++;
        }
    } else if(m == 2) {
        if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
            if (d > 29) {
                d -= 29;
                m++;
            }
        } else {
            if (d > 28) {
                d -= 28;
                m++;
            }
        }
    } else {
        if(d > 31) {
            d -= 31;
            m++;
        }
        if(m > 12) {
            m -= 12;
            y++;
        }
    }
    printf("%d %d %d", y, m, d);
    return 0;
}