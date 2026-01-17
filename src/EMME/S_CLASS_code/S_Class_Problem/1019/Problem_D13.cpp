//
// Created by Emma on 2025/8/5.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int space = n, xing = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        for (int j = 1; j <= xing; j++) {
            cout << "*";
        }
        space--;
        xing += 2;
        cout << endl;
    }
    return 0;
}

/*
　　　  ＊
   　 ＊＊＊
    ＊＊＊＊＊
  ＊＊＊＊＊＊＊
＊＊＊＊＊＊＊＊＊
*/