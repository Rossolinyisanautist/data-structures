#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		string problem;
		cin >> problem;

		if(problem.find("P=NP") != string::npos)  {
			cout << "skipped\n";
			continue;
		}
		 
		int a = stoi( problem.substr(0, problem.find('+')) );
		int b = stoi( problem.substr(problem.find('+') + 1) );
		cout << (a + b) << '\n';
	}
}