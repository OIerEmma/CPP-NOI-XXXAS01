#include <string>
#include <iostream>
using namespace std;
//
// Created by Geek.Kwok on 2026/2/18.
//
class Person {
    string name;
    int age;
    int sex;

public:
    static string skin;

    Person(string name, int age, int sex) {
        skin = "yellow";
        this->name = name;
        this->age = age;
        this->sex = sex;
    }
    string getName() {
        return name;
    }
    int getSex() {
        return sex;
    }
    int getAge() {
        return age;
    }
};

int main() {
    Person* p = new Person("GuoMingxuan", 13, 1);
    cout << p->getName() << endl;
    cout << p->getAge() << endl;
    cout << p->getSex() << endl;
    cout << Person::skin << endl;

    return 0;
}