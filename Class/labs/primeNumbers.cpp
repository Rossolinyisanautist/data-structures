#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int a);

int main() {
	int begin;
	int end;

	cin >> begin >> end;

	if(begin > end) swap(begin, end);
	
	vector<int> primes;

	clock_t startTime = clock();
	for (int i = begin; i < end; i++) {
		if(isPrime(i)) {
			primes.push_back(i);
		}
	}
	clock_t endTime = clock();

	cout << "[ ";
	for(int num : primes) {
		cout << num << " ";
	}
	cout << " ]\n";
	cout << "Time spent: " << double(endTime - startTime) / CLOCKS_PER_SEC << '\n';
}

bool isPrime(int n) {
	if(n == 1) return false;
	
	if(n == 2) return true;
	
	if(n % 2 == 0) return false;
	
	for(int i = 3; i * i <= n; i += 2) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}






