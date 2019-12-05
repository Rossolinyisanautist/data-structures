#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << ":" << '\n';
    int sum;


    int i = 1, 
        j = 1, 
        timesI = n / 2 + 1, 
        timesJ = n / 2;

    while(i > 1) {
        sum = i * timesI + j * timesJ;

        if (sum == n) {
        	cout << i << ',' << j << '\n';
            timesI = n / 2 + 1;
            timesJ = n / 2;
            if (j == i) {
                i++;
            }
            else if(i > j) {
                j++;
            }
        }

        if (sum < n) {
            if (j == i) {
                i++;
            }
            else if(i > j) {
                j++;
            }
        }
        if (sum > n) {
            if (timesI == timesJ) {
                timesJ--;
            }
            else if(timesI > timesJ) {
                timesI--;
            }
        }
    }
    
}

/*

2 1


3

* 
*

* *
*

* *
 *

*/