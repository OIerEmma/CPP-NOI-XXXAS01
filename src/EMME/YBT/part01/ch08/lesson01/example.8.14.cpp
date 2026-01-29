//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

struct stu {
    char name[20];
    char sex;
    int score;
} s[3] = {{"xiaoming", 'f', 356}, {"xiaoliang", 'f', 350}, {"xiaohong", 'm', 0}};

int main() {
    stu *p;
    printf("Name       Sex  Score\n");
    for (p = s; p < s + 3; p++) {
        printf("%-9s%3c%7d\n", p->name, p->sex, p->score);
    }
    return 0;
}
