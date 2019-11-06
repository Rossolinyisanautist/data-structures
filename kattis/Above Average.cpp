#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int n2;
		double sum = 0;
		cin >> n2;
		int grades[n2];
		for (int i = 0; i < n2; ++i) {
			cin >> grades[i];
			sum += grades[i];
		}
		double avg = sum / n2;
		int count = 0;
		for (int i = 0; i < n2; ++i) {
			count += grades[i] > avg;
		}
		double percent = ((double) count / n2) * 100.0;
		cout << fixed << setprecision(3) << percent << "%\n";
	}
}