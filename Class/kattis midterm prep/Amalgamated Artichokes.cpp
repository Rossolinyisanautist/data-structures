#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double calcPrice(int p, int a, int b, int c, int d, int k) {
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main() {
	int p, a, b, c, d, n, k = 1;
	cin >> p >> a >> b >> c >> d >> n;

	double maxPrice = calcPrice(p, a, b, c, d, k);
	k++;
	double decline = 0;

	while(k <= n) {
		double price = calcPrice(p, a, b, c, d, k);

		if(price < maxPrice) {
			decline = max(decline, maxPrice - price);
		}
		else {
			maxPrice = price;
		}
		k++;
	}
	cout << fixed << setprecision(9) << decline << '\n';
}

