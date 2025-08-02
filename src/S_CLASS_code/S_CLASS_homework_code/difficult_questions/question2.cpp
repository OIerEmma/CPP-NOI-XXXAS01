//
// Created by Emma on 2025/2/2.
//
#include<iostream>
using namespace std;

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf\n", &a, &b, &c, &d);
    double x = (a * 2 + b * 3 + c * 4 + d) / 10;
    printf("Media: %.1lf\n", x);
    if(x >= 7.0) {
        printf("Aluno aprovado.\n");
    } else if(x < 5.0) {
        printf("Aluno reprovado.\n");
    } else {
        printf("Aluno em exame.\n");
        double y;
        scanf("%lf", &y);
        printf("Nota do exame: %.1lf\n", y);
        double z = (x + y) / 2;
        if(z > 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1lf\n", z);
    }
    return 0;
}