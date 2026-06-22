//
// Created by Geek.Kwok on 2026/5/1.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person {
public:
    static string TAG;

    string name;
    int age;

    Person(string n, int g): name(n), age(g) {}
};

#endif //PERSON_H
