//
// Created by Emma on 2025/8/19.
//
#include<iostream>
using namespace std;

int a[101];

int main() {
    int n, d;
    string name;
    cout << "Hello! I am your AI robot Smarty! What is your name? You need to put an endl in the end! Input here:";
    cin >> name;
    cout << "Hi! " << name << endl << "OK Now " << name << ", ";
    cout << "Please enter a number(n) base 10, notice! you need to put an endl in the end too:" << endl;
    cin >> n;
    cout << "Good! And now please enter a number(d) base 10, notice! you need to put an endl in the end again:" << endl;
    cin >> d;
    cout << "What smart you are! And now I can help you do the cauculate! Please wait a moment!" << endl;
    int i = 0;
    do {
        a[++i] = n % d;
        n = n / d;
    } while (n != 0);
    cout << "OK! the answer is:";
    for (int j = i; j >= 1; j--) {
        cout << a[j];
    }
    return 0;
}
