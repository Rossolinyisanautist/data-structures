#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector v = {5, 0, 1, 6, 0, 3, 3, 0, 10, 2};

	cout << "zeros: " << count(v.begin(), v.end(), 0) << '\n';
	cout << "zeros: " << count(v.begin(), v.size() / 2 + v.begin(), 0) << '\n';
	cout << "zeros: " << count(v.size() / 2 + v.begin(), v.end(), 0) << '\n';

	auto maxP = max_element(v.begin(), v.end());
	auto minP = min_element(v.begin(), v.end());

	cout << "max: " << *maxP << '\n';
	cout << "min: " << *minP << '\n';

	cout << "distance: " << abs(maxP - minP) << '\n';
	cout << "max index: " << maxP - v.begin() << '\n';
	cout << "min index: " << minP - v.begin() << '\n';

	cout << "enter number to find: ";
	int n;
	cin >> n;
	auto nIndex = find(v.begin(), v.end(), n);
	cout << "number " << n << " is fount at position " << nIndex - v.begin() << '\n';
	
 }