//
// Created by Emma on 2024/11/9.
//
#include <cstdio>
using namespace std;

int main()
{
    float s, h, up, down;
    up = 15;
    down = 25;
    h = 2 * 150 / up;
    s = (up + down) * h / 2;
    printf("s = %0.2f\n", s);
    return 0;
}