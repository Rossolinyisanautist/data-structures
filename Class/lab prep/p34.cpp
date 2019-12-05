#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
using namespace std;

bool isPrimeSlow(int n) {
	if(n == 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;

	for (int i = 3; i < n; i += 2) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

bool isPrimeFast(int n) {
	if(n == 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;

}

int main() {
	int start, end, counter = 0;
	cin >> start >> end;

	if(start > end) swap(start, end);

	clock_t beginTime = clock();
	for (int i = start; i < end; ++i) {
		counter += isPrimeSlow(i);
	}
	clock_t endTime = clock();

	cout << "Time spent with isPrimeSlow: " << fixed << double(endTime - beginTime) / CLOCKS_PER_SEC << '\n';
	cout << "Number of primes: " << counter << '\n';

	counter = 0;
	beginTime = clock();
	for (int i = start; i < end; ++i) {
		counter += isPrimeFast(i);
	}
	endTime = clock();

	cout << "Time spent with isPrimeFast: " << fixed << double(endTime - beginTime) / CLOCKS_PER_SEC << '\n';
	cout << "Number of primes: " << counter << '\n';
}









