//
// Created by Emma on 2025/2/10.
//
#include<iostream>
#include<string>
using namespace std;
char s1[1000000000], s2[1000000000];
int i, j;
size_t l1, l2;

int main() {
    cin.getline(s1, 105);
    cin.getline(s2, 105);
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (int i = 0, j = 0; i < l1 || j < l2;) {
        if (s1[i] == ' ') {
            i++;
        } else if (s2[j] == ' ') {
            j++;
        } else {
            if (s1[i] == s2[j] || s1[i] == s2[j] + 32 || s1[i] + 32 == s2[j]) {
                i++;
                j++;
            } else {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
