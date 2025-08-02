//
// Created by Emma on 2025/2/2.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, maxvalue = -1, minvalue = 1000000, middle;
    scanf("%d %d %d", &a, &b, &c);
    maxvalue = max(maxvalue, max(a, max(b, c)));
    minvalue = min(minvalue, min(a, min(b, c)));
    if(a != maxvalue && a != minvalue) {
        middle = a;
    } else if(b != maxvalue && b != minvalue) {
        middle = b;
    } else {
        middle = c;
    }
    a = maxvalue, b = middle, c = minvalue;
    if(a >= b + c) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if(a * a == b * b + c * c) {
            printf("TRIANGULO RETANGULO\n");
        } else if(a * a > b * b + c * c) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else if(a * a < b * b + c * c) {
            printf("TRIANGULO ACUTANGULO\n");
        }
        if(a == b && b == c){
            printf("TRIANGULO EQUILATERO\n");
        } else {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}