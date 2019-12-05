#include<iostream>
#include<cstdint>
using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	if(a <= b) goto L1;	
	swap(a, b);
L1:
	int i = a;
	int64_t sum = 0;
L2:
	if(i > b) goto L3;
	sum += i;
	i++;
	goto L2;
L3:
	cout << "sum(" << a << ", " << b << ") = " << sum << '\n';
	sum = ( (a + b) * (b - a + 1) ) /2;
	cout << "sum(" << a << ", " << b << ") = " << sum << '\n';
}