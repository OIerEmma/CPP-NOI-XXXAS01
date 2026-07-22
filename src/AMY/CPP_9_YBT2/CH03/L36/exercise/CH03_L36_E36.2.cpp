#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int count = 0;
    // x must be in [0, c/a]
    for (int x = 0; x <= c / a; x++) {
        int remainder = c - a * x;
        if (remainder % b == 0) {
            int y = remainder / b;
            if (y >= 0) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}