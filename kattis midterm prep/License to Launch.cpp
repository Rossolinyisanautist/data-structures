#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long mininmum = 1000000001, index = -1;
	for (long i = 0, junks; i < n; ++i)	{
		cin >> junks;
		index = junks < mininmum ? i : index;
		mininmum = min(junks, mininmum);
	}	
	cout << index << '\n';
}
