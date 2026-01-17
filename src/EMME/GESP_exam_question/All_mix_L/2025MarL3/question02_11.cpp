//
// Created by Emma on 2025/3/22.
//
#include<iostream>
#include<cstring>
using namespace std;

string to_lower(string source) {
    char ans[source.size()];
    for (int i = 0; i < source.size(); i++) {
        if (source[i] >= 'A' && source[i] <= 'Z') {
            ans[i] = char(source[i] + (97 - 65));
        } else {
            ans[i] = source[i];
        }
    }
    return ans;
}

int main() {
    int n, number = 0;
    cin >> n;
    string str[n], s;
    int num[n];
    memset(num, 0, sizeof(num));
    for (int i = 0, j; i < n; i++) {
        cin >> s;
        s = to_lower(s);
        for (j = 0; j < number; j++) {
            if (str[j] == s) {
                num[j]++;
                break;
            }
        }
        if (j >= number) {
            str[number++] = s;
            num[number]++;
        }
    }
    int maxindex = -1, maxvalue = 0;
    for (int i = 0; i < number; i++) {
        if (maxvalue < num[i]) {
            maxvalue = num[i];
            maxindex = i;
        }
    }
    cout << str[maxindex] << endl;
    return 0;
}
