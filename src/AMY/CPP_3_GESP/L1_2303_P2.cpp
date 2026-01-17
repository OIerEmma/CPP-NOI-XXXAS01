
#include <iostream>
using namespace std;

int main() {
    long long a;
    cin >> a;
    int b = 0;
    for (long long i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            b++;
        }
    }
    cout << b << endl;
    return 0;
}