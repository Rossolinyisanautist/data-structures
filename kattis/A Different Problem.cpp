#include<iostream>
#include<cstdint>

using namespace std;

int main() {
	int64_t a, b;

	while(cin >> a >> b) {
		cout << abs(a - b) << endl;
	}
}

int absVal(int64_t value) {
	return value < 0 ? -value : value;
}
