#include <iostream>

using namespace std;

int main() {
    char c;
    int countW = 0;
    int countB = 0;

    while(cin >> c) {
        countW += (c == 'W');
        countB += (c == 'B');
    }
    cout << (countW == countB) << '\n';
}