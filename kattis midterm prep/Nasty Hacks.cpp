#include<iostream>

using namespace std;

int main() {
	int n, r, e, c;
	cin >> n;
	while(n--) {
		cin >> r >> e >> c;
		e -= c;
		if(r == e) {
			cout << "does not matter\n";
		}
		else if(r > e) {
			cout << "do not advertise\n";
		}
		else {
			cout << "advertise\n";
		}
	}
}