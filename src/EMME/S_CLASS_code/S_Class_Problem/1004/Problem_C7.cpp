//
// Created by Emma on 2025/7/6.
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    char k[101], s[1001];
    cin >> k >> s;
    int k_len = strlen(k);
    for (int i = 0; i < strlen(s); i++) {
        int const base = isupper(s[i]) ? 65 : 97;
        s[i] = char(base + ((s[i] - base) - (tolower(k[i % k_len]) - 97) + 26) % 26);
    }
    cout << s << endl;
    return 0;
}

/*
int main() {
    char k[101], s[1001];
    cin >> k >> s;
    int k_len = strlen(k);
    for (int i = 0; i < strlen(s); i++) {
        int offset = tolower(k[i % k_len]);
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] - (offset - 97) < 65) {
                s[i] += 26;
            }
            s[i] = char(s[i] - (offset - 97));
        } else {
            if (s[i] - (offset - 97) < 97) {
                s[i] += 26;
            }
            s[i] = char(s[i] - (offset - 97));
        }
    }
    cout << s << endl;
    return 0;
}
*/