//
// Created by Emma on 2025/2/4.
//
// #include<iostream>
// #include<cstdio>
// #include<cmath>
// using namespace std;
//
// int main() {
//     double a, b, c;
//     cin >> a >> b >> c;
//     double const x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
//     double const x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
//     if(sqrt(a * x1 * x1 + b * x2 + c) == 0) {
//         printf("No answer!");
//     }
//     if(x1 == x2) {
//         printf("x1=x2=%.5lf", x1);
//     } else {
//         printf("x1=%.5lf;x2=%.5lf", x1, x2);
//     }
//     return 0;
// }
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta < 0)
        cout << "No answer!";
    else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        if (x1 == x2) printf("x1=x2=%.5lf", x1);
        else if (x1 > x2)
            printf("x1=%.5lf;x2=%.5lf", x2, x1);
        else
            printf("x1=%.5lf;x2=%.5lf", x1, x2);
    }
    return 0;
}
