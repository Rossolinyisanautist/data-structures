#include<iostream>

using namespace std;

int main() {
	for(;;) {
		int n, miles = 0;
		cin >> n;
		if(n == -1) break;

		int sp, tm, prev;
		cin >> sp >> tm;
		miles += sp * tm;
		prev = tm;
		n--;
		while(n--) {
			cin >> sp >> tm;
			miles += (tm - prev) * sp;
			prev = tm;
		}
		cout << miles << " miles\n";
	}
}