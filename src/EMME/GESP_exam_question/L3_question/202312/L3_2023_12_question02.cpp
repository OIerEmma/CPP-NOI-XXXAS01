//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int fn;
        string fu, bu;
        char equal, qmark;
        cin >> fn >> fu >> equal >> qmark >> bu;
        cout << fn << " " << fu << " " << equal << " ";
        if (fu[0] == 'k') {
            if (bu == "m" || bu == "g") {
                cout << fn * 1000;
            } else if (bu == "mm" || bu == "mg") {
                cout << fn * 1000000;
            }
        } else if (fu == "m" || fu == "g") {
            cout << fn * 1000;
        }
        cout << " " << bu << endl;
    }
    return 0;
}