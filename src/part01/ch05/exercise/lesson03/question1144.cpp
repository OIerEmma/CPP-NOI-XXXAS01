//
// Created by Emma on 2025/2/16.
//
#include<iostream>
using namespace std;

int main() {
    string input;
    char line[500];
    int i = 0, index, pos = 0;
    memset(line, '\0', sizeof(line));
    getline(cin, input);
    for (index = pos; i < input.size(); i++) {
        if (input[i] == ' ') {
            for (int start = i - 1; start >= pos; start--) {
                line[index++] = input[start];
            }
            do {
                line[index++] = input[i];
            } while (input[++i] == ' ');
            pos = i--;
        }
    }
    for (int start = i - 1; start >= pos; start--) {
        line[index++] = input[start];
    }
    // line[index] = '\0';
    cout << line << endl;
    return 0;
}