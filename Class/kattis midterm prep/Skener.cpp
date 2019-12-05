#include<iostream>
#include<vector>

using namespace std;

int main() {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;

	vector<string> lines;

	for (int i = 0; i < r; ++i) {
		string temp;
		cin >> temp;
		lines.push_back(temp);
	}
	
	string lineToPrint = "";
	for (int i = 0; i < r; ++i) {
		for(int j = 0; j < lines[i].length(); j++) {
			lineToPrint.insert(lineToPrint.length(), zc, lines[i][j]);
		}
		for(int j = 0; j < zr; j++) {
			cout << lineToPrint << '\n';
		}
		lineToPrint = "";
	}
}