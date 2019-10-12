#include <iostream>

using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while(num > 0) {
        int digit = num % 10;
        num /= 10;
        sum += digit;
    }
    return sum;
}

int main() {
    int L, D, X, isMinFound = 0, maxN;
    cin >> L >> D >> X;
    int i = L;

    while(sumOfDigits(i) <= 36 && i <= D) {
        if(sumOfDigits(i) == X) {
            if(isMinFound) {
                maxN = max(maxN, i);
            }
            else {
                cout << i << '\n';
                maxN = max(maxN, i);
                isMinFound = 1;         
            }
        }
        i++;
    } 
    cout << maxN << '\n';
}