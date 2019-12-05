#include<iostream>

using namespace std;

int main() {
	int n, sum = 0, count = 0;
	cin >> n;
	while(n--) {
		int temp;
		cin >> temp;
		if(temp != -1) {
			sum += temp;;
			count++;
		}
	}
	cout << (double) sum / count << '\n';
}