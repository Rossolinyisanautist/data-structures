#include<iostream>

using namespace std;

int main() {
	int times;
	cin >> times;
	string before, after, correct;
	cin >> before >> after;
	correct = before;

	if(times % 2 != 0) {
		correct = "";
		for (int i = 0; i < before.length(); ++i) {
			correct += before[i] == '1' ? '0' : '1';
		}
	}
	cout << ((after == correct) ? "Deletion succeeded\n" : "Deletion failed\n");	
}