#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	while(cases--) {
		string str;
		cin >> str;

		int L = str.length();
		int K = sqrt(L);
		while(K * K < L) {
			K++;
		}
		str.insert(L, K*K - L, '*');
		string m[K];

		int j = 0;
		for (int i = 0; i < K; ++i) {
			m[i] = str.substr(j, K);
			j += K;
		}

		for(int j = 0; j < K; j++) {
			for(int i = K - 1; i >= 0; i--) {
				if(m[i][0 + j] != '*') {
					cout << m[i][0 + j] ;
				}
			}
		}
		cout << '\n';
	}
}