#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	int p, a, b, c, d, n, k = 2;

	cin >> p >> a >> b >> c >> d >> n;

	double result, maxPrice = p * (sin(a + b) + cos(c + d) + 2);

	while(k <= n) {
		double currentPrice = p * (sin(a * k + b) + cos(c * k + d) + 2);

		if (currentPrice < maxPrice) {
			result = max(maxPrice - currentPrice, result);
		}
		else if (currentPrice >= maxPrice) {
			maxPrice = currentPrice;
		}
		k++;
		//𝑝⋅(sin(𝑎⋅𝑘+𝑏)+cos(𝑐⋅𝑘+𝑑)+2)
	}
	cout << fixed << result << endl;

}