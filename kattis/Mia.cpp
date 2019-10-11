
#include <iostream>

using namespace std;

int main() {
    while(true) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if( a + b + c + d == 0 ) break;

        if( (a == 1 && b == 2) || (a == 2 && b == 1) ) {
            if( (c == 1 && d == 2) || (c == 2 && d == 1) ) {
                cout << "Tie.\n";
            }
            else {
                cout << "Player 1 wins.\n";
            }
        }
        else if( (c == 1 && d == 2) || (c == 2 && d == 1) ) {
            cout << "Player 2 wins.\n";
        }
        else if ( a == b ) {
            if(c == d) {
                int num1 = a + b;
                int num2 = c + d;

                if(num1 == num2) {
                    cout << "Tie.\n";
                }
                else if(num1 > num2) {
                    cout << "Player 1 wins.\n";             
                }
                else {
                    cout << "Player 2 wins.\n";
                }
            }
            else {
                cout << "Player 1 wins.\n";
            }
        }
        else if( c == d ) {
            cout << "Player 2 wins.\n";
        }
        else {
            if(a < b) swap(a, b);
            if(c < d) swap(c, d);

            int num1 = stoi( to_string(a) + to_string(b) );
            int num2 = stoi( to_string(c) + to_string(d) );

            if(num1 == num2) {
                cout << "Tie.\n";
            }
            else if(num1 > num2) {
                cout << "Player 1 wins.\n";             
            }
            else {
                cout << "Player 2 wins.\n";
            }
        }
    }
}